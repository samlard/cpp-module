template <typename T>
Array<T>::Array() : _array(NULL), _len(0){}

template <typename T> 
Array<T>::~Array() {
    delete [] _array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _len(n){}

template <typename T> 
Array<T>::Array(const Array<T> &src) :_array(new T[src._len]()), _len(src._len)
{
    for (size_t i = 0; i < _len; i++)
        _array[i] = src._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &src){
    if (this != &src)
    {
        delete [] _array;
        _len = src._len;
        _array = new T[src._len]();
        for (size_t i = 0; i < _len; i++)
            _array[i] = src._array[i];
    }
    return *this;
}

template <typename T>
const T &Array<T>::operator[](size_t index)const {
    if (index >= _len)
        throw ArrayException();
    return _array[index];
}

template <typename T>
T &Array<T>::operator[](size_t index){
    if (index >= _len)
        throw ArrayException();
    return _array[index];
}

template <typename T>
size_t Array<T>::size()const {
    return _len;
}