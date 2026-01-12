#include <iostream>
#include <cstring>

class TodoItem
{
  // this time our public interface for this class comes first.
public:
  TodoItem(const char *description);
  ~TodoItem();
  void complete();
  std::string display();
  // to declare private state later, jus add the private section
private:
  char *description;
  bool completed;
};

TodoItem::TodoItem(const char *desc)
{
  // allocate memory for description
  description = new char[strlen(desc) + 1];
  strcpy(description, desc);
  completed = false;
  std::cout << "Created todo item: " << this << std::endl;
}

TodoItem::~TodoItem()
{
  // the memory we allocated gets freed here
  free(description);
  std::cout << "Deleted todo item: " << this << std::endl;
  // this is a special pointer to the current object
}

void TodoItem::complete()
{
  completed = true;
}

std::string TodoItem::display()
{
  return std::string(completed ? "[x] " : "[ ] ") + description;
}

int main()
{
  // these goes on stack
  TodoItem item1("Learn C++ classes");
  TodoItem item2("Build a todo list app");
  // this goes on heap. the new operator returns a pointer to the allocated memory
  TodoItem *item3 = new TodoItem("heap the pointer");

  std::cout << item1.display() << std::endl;
  std::cout << item2.display() << std::endl;
  std::cout << item3->display() << std::endl;

  item1.complete();

  std::cout << item1.display() << std::endl;
  std::cout << item2.display() << std::endl;
  std::cout << item3->display() << std::endl;

  // since item3 was allocated on the heap, we need to free it manually
  delete item3;
  // after the function ends, item1 and item2 go out of scope and their
  // destructors are called automatically
  return 0;
}