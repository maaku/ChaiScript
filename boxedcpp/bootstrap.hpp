#ifndef __bootstrap_hpp
#define __bootstrap_hpp__

#include "boxedcpp.hpp"

template<typename Ret, typename P1, typename P2>
Ret add(P1 p1, P2 p2)
{
  return p1 + p2;
}

template<typename Ret, typename P1, typename P2>
Ret subtract(P1 p1, P2 p2)
{
  return p1 - p2;
}

template<typename Ret, typename P1, typename P2>
Ret divide(P1 p1, P2 p2)
{
  return p1 - p2;
}


template<typename Ret, typename P1, typename P2>
Ret multiply(P1 p1, P2 p2)
{
  return p1 * p2;
}

template<typename Ret, typename P1, typename P2>
Ret equals(P1 p1, P2 p2)
{
  return p1 == p2;
}

template<typename P1, typename P2>
P1 &timesequal(P1 &p1, P2 p2)
{
  return (p1 *= p2);
}

template<typename Input>
std::string to_string(Input i)
{
  return boost::lexical_cast<std::string>(i);
}

void bootstrap(BoxedCPP_System &s)
{
  s.register_type<void>("void");
  s.register_type<double>("double");
  s.register_type<int>("int");
  s.register_type<char>("char");
  s.register_type<bool>("bool");
  s.register_type<std::string>("string");

  s.register_function(boost::function<std::string (const std::string &, const std::string&)>(&add<std::string, const std::string &, const std::string &>), "+");

  s.register_function(boost::function<int (int, int)>(&add<int, int, int>), "+");
  s.register_function(boost::function<double (int, double)>(&add<double, int, double>), "+");
  s.register_function(boost::function<double (double, int)>(&add<double, double, int>), "+");
  s.register_function(boost::function<double (double, double)>(&add<double, double, double>), "+");

  s.register_function(boost::function<int (int, int)>(&subtract<int, int, int>), "-");
  s.register_function(boost::function<double (int, double)>(&subtract<double, int, double>), "-");
  s.register_function(boost::function<double (double, int)>(&subtract<double, double, int>), "-");
  s.register_function(boost::function<double (double, double)>(&subtract<double, double, double>), "-");

  s.register_function(boost::function<int (int, int)>(&divide<int, int, int>), "/");
  s.register_function(boost::function<double (int, double)>(&divide<double, int, double>), "/");
  s.register_function(boost::function<double (double, int)>(&divide<double, double, int>), "/");
  s.register_function(boost::function<double (double, double)>(&divide<double, double, double>), "/");

  s.register_function(boost::function<int (int, int)>(&equals<bool, int, int>), "==");
  s.register_function(boost::function<double (int, double)>(&equals<bool, int, double>), "==");
  s.register_function(boost::function<double (double, int)>(&equals<bool, double, int>), "==");
  s.register_function(boost::function<double (double, double)>(&equals<bool, double, double>), "==");

  s.register_function(boost::function<int (int, int)>(&multiply<int, int, int>), "*");
  s.register_function(boost::function<double (int, double)>(&multiply<double, int, double>), "*");
  s.register_function(boost::function<double (double, int)>(&multiply<double, double, int>), "*");
  s.register_function(boost::function<double (double, double)>(&multiply<double, double, double>), "*");

  s.register_function(boost::function<std::string (int)>(&to_string<int>), "to_string");
  s.register_function(boost::function<std::string (const std::string &)>(&to_string<const std::string &>), "to_string");
  s.register_function(boost::function<std::string (char)>(&to_string<char>), "to_string");
  s.register_function(boost::function<std::string (double)>(&to_string<double>), "to_string");

  s.register_function(boost::function<int &(int&, int)>(&timesequal<int, int>), "*=");
  s.register_function(boost::function<double &(double&, int)>(&timesequal<double, int>), "*=");
  s.register_function(boost::function<double &(double&, double)>(&timesequal<double, double>), "*=");
  s.register_function(boost::function<int &(int&, double)>(&timesequal<int, double>), "*=");

}

#endif