#include<iostream> 
#include<stdlib.h>
#include"LinearList.h"
using namespace std;
const int defaultSize = 100;
template<class T>
class SeqList: public LinearList<T> {
      protected:
                T *data;                // �ײ��������ʵ�� 
                int maxSize;            // �������󳤶�
                int last;
                void reSize(int newSize);
      public:
             SeqList(int sz = defaultSize); 
             SeqList(SeqList<T>& L);
             ~SeqList(){delete[] data;}
             int Size() const{return maxSize;}          // ����˳������󳤶� 
             int Length() const{return last + 1;}
             int Search(T& x)const;
             int Locate(int i)const;
             bool getData(int i, T& x) const;
             void setData(int i, T& x);
             
             bool Insert(int i, T& x);
             bool Remove(int i, T& x);
             bool IsEmpty()const;
             bool IsFull()const;
             void Sort();
             void input();
             void output();
             SeqList<T> operator=(SeqList<T>& L);
};
             template<class T>
             bool SeqList<T>::getData(int i, T& x)const{              // ���ص�i������ 
                  if (i > 0 && i <= last + 1) {
                        x = data[i - 1];
                        return true;
                  } else
                        return false;
             }
             template<class T>
             void SeqList<T>::setData(int i, T& x) {
                  if (i > 0 && i <= last + 1) {
                        data[i - 1] = x;
                  }
             }
             template<class T>
             bool SeqList<T>::IsEmpty()const {
                  return last == -1;
             }
             template<class T>
bool SeqList<T>::IsFull()const {
                  return (last == maxSize - 1) ? true : false;
             }
template<class T>
SeqList<T>::SeqList(int sz) {
    if (sz > 0) {
       maxSize = sz;
       last = -1;
       data = new T[maxSize];
       if (data == NULL) {
                cerr<<"�洢�������"<<endl;
                exit(1);
       }
    }
}

template<class T>
SeqList<T>::SeqList(SeqList<T>& L) {
    if (L != NULL) {
          maxSize = L.Size();
          last = L.length() - 1;
          data = new T[L.Size()];
          if (data == NULL) {
                cerr<<"�洢�������"<<endl;
                exit(1);
       }
          for (int i = 0; i <= last; i++)
              L.getData(i + 1, data[i]);
    }
}

template<class T>
int SeqList<T>::Search(T& x) const {
    for (int i = 0; i <= last; i++) {
        if (x == data[i])
           return i + 1;
    }
    return -1;
}

template<class T>
int SeqList<T>::Locate(int i)const {
    if (i > 0 && i <= last + 1) {
       return i;
    }
    return -1;
}

// �����i���±� 
template<class T>
bool SeqList<T>::Insert(int i, T& x) {
     if (IsFull() || i < 0 || i > last + 1) return false;
     int j = last;
     while(j >= i) {
         data[j + 1] = data[j];
         j--;
     }
     data[i] = x;
     last++; // �����Ҫ�� 
     return true;
}

template<class T>
bool SeqList<T>::Remove(int i, T& x) {
     if (IsEmpty() || i < 0 || i > last)
        return false;
     x = data[i];
     while(i < last) {
        data[i] = data[i + 1];
     }
     return true;
}

template<class T>
void SeqList<T>::Sort(){
     
}

template<class T>
void SeqList<T>::input() {
     cout<<"������˳������һ����ЧԪ�ص��±�: ";
     while(1) {
              cin>>last;
              if (last <= maxSize - 1) break;
                      cout<<"��Ԫ�ظ����������󣬷�Χ���ܳ���"<<maxSize - 1<<": ";         
     } 
     cout<<"�����Ԫ��"<<endl;
     for (int i = 0; i <= last; i++) {
         cin>>data[i];
         cout<<i + 1<<endl;
     }
}

template<class T>
void SeqList<T>::output() {
     cout<<"˳����ܴ�С��"<<Size()<<", ˳����ȣ�"<<Length()<<endl;
     for (int i = 0; i <= last; i++) {
         cout<<"#"<<i<<": "<<data[i]<<endl;    
     }     
}

template<class T>
SeqList<T> SeqList<T>::operator=(SeqList<T>& L) {
    return NULL;          
}


int main(int argc, char *argv[])
{
    SeqList<int> *LL = new SeqList<int>();
    //cout<<LL->Size();
    LL->input();
    LL->output();
    system("PAUSE");
    return EXIT_SUCCESS;
}

