#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deque(src._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _deque = src._deque;
    }
    return *this;
}

bool PmergeMe::parseInput(int ac, char **argv)
{
    for (int i  = 1; i < ac; i++)
    {
        std::string str(argv[i]);
        if (str.empty())
            return false;
        size_t j = 0;
        while (j < str.size())
        {
            if (!isdigit(str[j]))
                return false;
            j++;
        }
        char *endptr = NULL;
        long nbr = std::strtol(str.c_str(), &endptr, 10);
        if (*endptr != '\0')
            return false;
        if (nbr <= 0 || nbr > INT_MAX)
            return false;
        int value = static_cast<int>(nbr);
        std::vector<int>::iterator it = std::find(_vec.begin(), _vec.end(), value);
        if (it != _vec.end())
            return false;
        _vec.push_back(value);
        _deque.push_back(value);
    }
    return true;
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}

size_t PmergeMe::getVectorSize() const {
    return _vec.size();
}

size_t PmergeMe::getDequeSize() const {
    return _deque.size();
}

void PmergeMe::sortDeque(){
    fordJohnsonDeque(_deque);
}

void PmergeMe::sortVector(){
    fordJohnsonVector(_vec);
}

static std::vector<size_t> generateJacobsthal(size_t n)
{
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n)
    {
        size_t size = jacob.size();
        size_t next = jacob[size - 1] + 2 * jacob[size - 2];
        jacob.push_back(next);
    }
    return jacob;
}

static std::vector<size_t> buildInsertionOrder(size_t size)
{
    std::vector<size_t> jacob = generateJacobsthal(size);
    std::vector<size_t> order;
    size_t prev = 1;

    for (size_t i = 2; i < jacob.size(); i++)
    {
        size_t curr = jacob[i];
        if (curr > size)
            curr = size;
        for (size_t j = curr; j > prev; j--)
            order.push_back(j);
        prev = curr;
    }
    return order;
}

void PmergeMe::fordJohnsonVector(std::vector<int> &vec)
{
    if (vec.size() < 2)
        return;
    std::vector<std::pair<int,int> > pairs;
    bool hasOdd = (vec.size() % 2 != 0);
    int odd = 0;
    if (hasOdd)
        odd = vec.back();

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);
    fordJohnsonVector(mainChain);

    std::vector<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == mainChain[i])
            {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
    std::vector<int> result;
    result.push_back(pend[0]);
    for (size_t i = 0; i < mainChain.size(); ++i)
        result.push_back(mainChain[i]);

    std::vector<size_t> positions(mainChain.size());
    for (size_t i = 0; i < mainChain.size(); ++i)
        positions[i] = i + 1;

    std::vector<size_t> order = buildInsertionOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i] - 1;
        if (idx == 0) 
            continue;
        if (idx >= pend.size()) 
            continue;
        int val = pend[idx];
        std::vector<int>::iterator bound = result.begin() + positions[idx];
        std::vector<int>::iterator pos = std::upper_bound(result.begin(), bound, val);
        size_t insert_idx = std::distance(result.begin(), pos);
        result.insert(pos, val);
        for (size_t j = 0; j < positions.size(); ++j)
        {
            if (positions[j] >= insert_idx)
                positions[j]++;
        }
    }
    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::upper_bound(result.begin(), result.end(), odd);
        result.insert(pos, odd);
    }
    vec = result;
}
    
void PmergeMe::fordJohnsonDeque(std::deque<int> &deq)
{
    if (deq.size() < 2)
        return;
        
    std::vector<std::pair<int,int> > pairs;
    bool hasOdd = (deq.size() % 2 != 0);
    int odd = 0;
    if (hasOdd)
        odd = deq.back();
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    fordJohnsonDeque(mainChain);
    std::deque<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == mainChain[i])
            {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
    std::deque<int> result;
    result.push_back(pend[0]);
    for (size_t i = 0; i < mainChain.size(); ++i)
        result.push_back(mainChain[i]);

    std::vector<size_t> positions(mainChain.size());
    for (size_t i = 0; i < mainChain.size(); ++i)
        positions[i] = i + 1;  
    
    std::vector<size_t> order = buildInsertionOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i] - 1;
        if (idx == 0) 
            continue;
        if (idx >= pend.size())
            continue;
        int val = pend[idx]; 
        std::deque<int>::iterator bound = result.begin() + positions[idx];
        std::deque<int>::iterator pos = std::upper_bound(result.begin(), bound, val);
        size_t insert_idx = std::distance(result.begin(), pos);
        result.insert(pos, val);
        
        for (size_t j = 0; j < positions.size(); ++j)
        {
            if (positions[j] >= insert_idx)
                positions[j]++;
        }
    }
    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::upper_bound(result.begin(), result.end(), odd);
        result.insert(pos, odd);
    }
    deq = result;
}