#include <utility>
class resource {
  int x = 0;
};
class foo
{
  public:
    foo()
      : p{new resource{}}
    { }
//copy constructor -- rule of three	
    foo(const foo& other)
      : p{new resource{*(other.p)}}
    { }
//move constructor --rule of five
    foo(foo&& other)
      : p{other.p}
    {
      other.p = nullptr;
    }
//copy assignment operator -- rule of three
    foo& operator=(const foo& other)
    {
      if (&other != this) {
        
		delete p;
        p = nullptr;
        
		p = new resource{*(other.p)};
      }
      return *this;
    }
//move assignment operator --rule of five
    foo& operator=(foo&& other)
    {
      if (&other != this) {
        delete p;
        p = other.p;
        other.p = nullptr;
      }
      return *this;
    }
//destructor -- rule of three
    ~foo()
    {
      delete p;
    }
  private:
    resource* p;
};