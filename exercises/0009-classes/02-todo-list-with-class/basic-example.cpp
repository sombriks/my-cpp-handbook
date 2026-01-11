#include <string>

class TodoItem
{
  std::string description;
  bool completed;
  TodoItem *next;
  TodoItem *prev;
};
