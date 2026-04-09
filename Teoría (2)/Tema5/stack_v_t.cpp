template<class T>
    class stack_v_t{

private:    
        vector_t<T> v_;
        int top_;
public:

stack_v_t(int max_sz): v_(max sz_), top(-1){}
~stack_v_t(void) {}

bool empty(void) const{
    
    return (top_ < 0);
    }
bool full(void) const{

    return (top_ == v_get_size() - 1);
    }
/// @brief Operación De Inserción(Push)
/// @param dato 
void push (const T& dato){ 
    assert(!full());
    top_++;
    v_[top_] = dato;
    }
/// @brief Operación De Extracción(Pop)
/// @param  
void pop(void){
    assert(!empty());
    top_--;
    }    
/// @brief Operación Lectura del Top
/// @param  
/// @return 
const T& top(void) const{   
    assert(!empty());
    return v_[top_];
    }




};