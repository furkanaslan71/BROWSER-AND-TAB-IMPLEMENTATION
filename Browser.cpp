#include "Browser.h"

Browser::Browser() 
{
    windows.append(Window());
}

void Browser::newWindow() 
{
    // TODO
    windows.append(Window());
}

void Browser::closeWindow() 
{
    // TODO
    if(windows.isEmpty()) return;
    windows.removeNodeAtIndex(0);
}

void Browser::switchToWindow(int index) 
{
    // TODO
    windows.moveToIndex(index, 0);
}

Window &Browser::getWindow(int index) 
{
    return (windows.getNodeAtIndex(index) -> data);
}

void Browser::moveTab(Window &from, Window &to) 
{
    // TODO
    Node<Tab> moving(from.getActiveTab());
    to.addTab(moving);
    from.closeTab();
    to.changeActiveTabTo(-2147483648);
    
}

void Browser::mergeWindows(Window &window1, Window &window2) 
{
    // TODO
    while(window2.isEmpty())
    {
        moveTab(window2, window1);
    }
    
}

void Browser::mergeAllWindows() 
{
    // TODO
    if(windows.getSize() > 0)
    {
        for(int i = 1; i<windows.getSize(); i++)
        {
            mergeWindows(getWindow(0), getWindow(1));
        }
    }
}

void Browser::closeAllWindows() 
{
    // TODO
    windows.removeAllNodes();
}

void Browser::closeEmptyWindows() 
{
    // TODO
    int k = 0;
    for(int i = 0; i<windows.getSize(); i++)
    {        
        if(getWindow(k).isEmpty())
        {
            closeWindow();
        }
        else k++;
    }
}

void Browser::print() 
{
    Node<Window> *head = windows.getFirstNode();
    if(head == NULL) 
    {
        std::cout << "The browser is empty" << std::endl;
    }
    else 
    {
        (head -> data).print();
        head = head -> next;
        while(head != windows.getFirstNode()) 
        {
            (head -> data).print();
            head = head -> next;
        }
    }
}
