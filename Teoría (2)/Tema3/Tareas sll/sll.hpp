#pragma once

#include <iostream>
#include <stack>

#include "sll_node.hpp"

namespace AyED
{

      template <class T>
      class sll
      {
      public:
            sll(void);
            virtual ~sll(void);

            void insert_head(sll_node<T> *n);
            sll_node<T> *extract_head(void);

            void insert_after(sll_node<T> *pred, sll_node<T> *n);
            sll_node<T> *extract_after(sll_node<T> *pred);

            sll_node<T> *head(void) const;

            bool empty(void) const;
            void write(std::ostream &os) const;

            sll_node<T> *tail(void);

            sll_node<T> *extract_tail(void);
            void insert_tail(sll_node<T> *n);

            bool only_one_item(void) const;

      private:
            sll_node<T> *head_;
      };

      template <class T>
      sll<T>::sll(void) : head_(NULL) {}

      template <class T>
      sll<T>::~sll(void)
      {
            while (!empty())
            {

                  sll_node<T> *aux{head_};
                  head_ = head_->get_next();
                  delete aux;
            }
      }

      template <class T>
      bool sll<T>::empty(void) const
      {
            return (head_ == NULL);
      }

      template <class T>
      sll_node<T> *sll<T>::tail(void)
      {
         //
      }

      template <class T>
      bool sll<T>::only_one_item(void) const
      {
            //
      }

      template <class T>
      sll_node<T> *sll<T>::extract_tail(void)
      {
           //
      }

      template <class T>
      void sll<T>::insert_tail(sll_node<T> *n)
      {
         //
      }


      template <class T>
      void sll<T>::insert_head(sll_node<T> *n)
      {
            n->set_next(head_);
            head_ = n;
      }

      template <class T>
      sll_node<T> *sll<T>::extract_head(void)
      {

            sll_node<T> *aux{head_};
            head_ = head_->get_next();
            aux->set_next(NULL);

            return aux;
      }

      template <class T>
      void sll<T>::insert_after(sll_node<T> *prev, sll_node<T> *n)
      {
            n->set_next(prev->get_next());
            prev->set_next(n);
      }

      template <class T>
      sll_node<T> *sll<T>::head(void) const
      {
            return head_;
      }

      template <class T>
      sll_node<T> *sll<T>::extract_after(sll_node<T> *prev)
      {
            sll_node<T> *aux{prev->get_next()};
            prev->set_next(aux->get_next());
            aux->set_next(NULL);

            return aux;
      }

      template <class T>
      void sll<T>::write(std::ostream &os) const
      {
            sll_node<T> *aux{head_};

            while (aux != NULL)
            {
                  aux->write(os);
                  aux = aux->get_next();
            }
      }

}