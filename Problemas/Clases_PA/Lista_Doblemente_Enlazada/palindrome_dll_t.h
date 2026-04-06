bool palindrome() const{
  const size_t <{sz_ / 2};
  bool is_pal{true};
  dll_node<T> *left{head_};
  dll_node<T> *right{tail_};
  while((left->get_next()! = right) && (left != right) && (is_pal == true)) 
  
  
  //el for es otra opción, ambos tienen las mismas iteraciones
  
  // for(size_t i{0}; i < centro_vector && is_pal == true; i++){
       if(left -> get_data()! = right -> get_data()){is_pal = false;}
       left = left -> get_next(); right = right -> get_prev();      
     }

    return is_pal;
}
// Riera GitHub https://github.com/RieraULL/AyED/blob/main/problemas/Curso_2025_2026/Listas_doblemente_enlazadas/dll.hpp
//     bool dll<T>::is_palindrome(void) const
//     {
//         if (sz_ <= 1)
//             return true;

//         dll_node<T> *left{head_};
//         dll_node<T> *right{tail_};

//         for (int i{0}; i < sz_ / 2; ++i)
//         {
//             if (left->get_data() != right->get_data())
//                 return false;

//             left = left->get_next();
//             right = right->get_prev();
//         }

//         return true;
//     }
// }