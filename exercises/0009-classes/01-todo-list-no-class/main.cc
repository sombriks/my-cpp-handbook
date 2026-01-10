#include <iostream>
#include <cstdlib>

struct TodoItem
{
  std::string description;
  bool completed;
  struct TodoItem *next;
  struct TodoItem *prev;
};

void addItem(TodoItem *&head, const std::string &description)
{
  TodoItem *newItem = (TodoItem *)malloc(sizeof(TodoItem));
  newItem->description = description;
  newItem->completed = false;
  newItem->next = nullptr;
  newItem->prev = nullptr;
  if (!head)
  {
    head = newItem;
  }
  else
  {
    TodoItem *temp = head;
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = newItem;
    newItem->prev = temp;
  }
}

void markCompleted(TodoItem *head, int index)
{
  TodoItem *temp = head;
  for (int i = 0; temp && i < index; ++i)
  {
    temp = temp->next;
  }
  if (temp)
  {
    temp->completed = true;
  }
}

void displayList(TodoItem *head)
{
  TodoItem *temp = head;
  int index = 0;
  while (temp)
  {
    std::cout << index++                                //
              << ". [" << (temp->completed ? 'x' : ' ') //
              << "] " << temp->description << '\n';
    temp = temp->next;
  }
}

void freeList(TodoItem *head)
{
  TodoItem *temp;
  while (head)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main()
{
  TodoItem *todoList = nullptr;
  addItem(todoList, "Buy groceries");
  addItem(todoList, "Walk the dog");
  addItem(todoList, "Read a book");

  std::cout << "Todo List:\n";
  displayList(todoList);

  std::cout << "\nMarking item 1 as completed.\n";
  markCompleted(todoList, 1);

  std::cout << "\nUpdated Todo List:\n";
  displayList(todoList);

  freeList(todoList);
  return 0;
}
