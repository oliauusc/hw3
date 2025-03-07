#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
std::vector<T> vect;
int m_;
PComparator c_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), c_(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
const T& Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vect[0];
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if (vect.size()==0)
    return true;
  else return false;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return (vect.size());
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) 
{
  vect.push_back(item);

int index = vect.size()-1;
int i = 0;

//trickle down algorithm
while (index > 0) {
  int parentIndex = (index-1)/m_;

  if (c_(vect[index], vect[parentIndex])) {
    std::swap(vect[parentIndex], vect[index]);
    index = parentIndex;
  }
  else break;
}
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty");
  }

//swap top and bottom
std::swap(vect[0], vect[vect.size()-1]);
vect.pop_back();

// T bestChild = vect[(m_*index)+1];
int index = 0;
int i = 0;

//trickle down algorithm
while (index < vect.size() && ((m_*index)+1) < vect.size()) {
  int bestChildIndex = m_*index+1;
  for (i = 1; i<=m_; i++) {
    if (((m_*index)+i) < vect.size()) {
      if (c_(vect[(m_*index)+i], vect[bestChildIndex])) {
        bestChildIndex = (m_*index)+i; 
      }
    }
  }

  if (c_(vect[bestChildIndex], vect[index])) {
    std::swap(vect[bestChildIndex], vect[index]);
    index = bestChildIndex;
  }
  else break;
}
}



#endif

