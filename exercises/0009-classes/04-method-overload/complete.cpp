// declare both versions on the class
class TodoItem
{
public:
  // other functions...
  void complete();
  void complete(const bool completed);
private:
  // other attributes
  bool completed;
};

// then the implementations

void TodoItem::complete()
{
  this->completed = true;
}

// the method overload
void TodoItem::complete(const bool completed)
{
  this->completed = completed;
}