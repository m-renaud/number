#ifndef MRR_NUMBER_HXX_
#define MRR_NUMBER_HXX_

//m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Copyright (c) 2012 Matt Renaud. All Rights Reserved.
//
// Email:  mrenaud92@gmail.com
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


#include <memory>

//m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

namespace mrr {

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-



//m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
struct number_concept
{
  virtual ~number_concept()
  {
  }

  virtual void operator++() = 0;

}; // struct number_concept



//m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
template <typename T>
struct concrete_number : public number_concept
{
  concrete_number(T const& n)
    : num(n)
  {
  }

  concrete_number(T&& n)
    : num(std::move(n))
  {
  }

  virtual void operator++() override final
  {
    ++num;
  }

  T num;

}; // struct concrete_number



//m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
struct number
{
public:
  template <typename T>
  number(T const& n)
    : num{std::make_shared<concrete_number<T>>(n)}
  {
  }

  ~number()
  {
  }

  number& operator ++()
  {
    ++(*num);
    return *this;
  }

private:
  std::shared_ptr<number_concept> num;

}; // struct number


//m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

} // namespace mrr

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#endif // #ifndef MRR_NUMBER_HXX_
