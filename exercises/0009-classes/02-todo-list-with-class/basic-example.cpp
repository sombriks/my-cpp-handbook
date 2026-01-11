#include <iostream>

class TodoItem
{
  std::string description;
  bool completed;
  TodoItem *next;
  TodoItem *prev;

public:
  TodoItem *toNext();
  TodoItem *toPrev();
  void complete();
  static void display(TodoItem *head);
  static void addItem(TodoItem *&head, const std::string &description);
};

void TodoItem::complete()
{
  completed = true;
}

TodoItem *TodoItem::toNext()
{
  return next;
}

TodoItem *TodoItem::toPrev()
{
  return prev;
}

void TodoItem::display(TodoItem *head)
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

void TodoItem::addItem(TodoItem *&head, const std::string &description)
{
  TodoItem *newItem = new TodoItem();
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

int main()
{
  TodoItem *head = nullptr;
  TodoItem::addItem(head, "Learn C++");
  TodoItem::addItem(head, "Build a project");
  TodoItem::addItem(head, "Contribute to open source");

  head->toNext()->complete(); // Mark the second item as completed

  TodoItem::display(head);

  return 0;
}