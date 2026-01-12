class MyClass
{
  int myPrivateState;

public:
  int myPublicMessage();
  // this function is a constructor
  MyClass();
  // this one is a destructor
  ~MyClass();
};

// function implementation
MyClass::MyClass()
{
}

// function implementation
MyClass::~MyClass()
{
}