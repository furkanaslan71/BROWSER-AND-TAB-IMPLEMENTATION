#include "Window.h"

Window::Window() 
{
    this->activeTab = 0;
    tabs.append(Tab());
}

Tab Window::getActiveTab() 
{
    // TODO
    if(tabs.getSize() == 0) return Tab();
    return (tabs.getNodeAtIndex(activeTab)->data);
}

bool Window::isEmpty() const 
{
    // TODO
    if(tabs.getSize() == 0) return true;
    else return false;
}

void Window::newTab(const Tab &tab) 
{
    // TODO
    if(tabs.getSize() == 0)
    {
        tabs.append(tab);
        activeTab = 0;
    }
    else
    {
        tabs.insertAfterNode(tab, tabs.getNodeAtIndex(activeTab));
        activeTab++;
    }
}

void Window::closeTab() 
{
    // TODO
    if(activeTab == -1)return;
    if(tabs.getSize() == 1)
    {
        tabs.removeNodeAtIndex(0);
        activeTab = -1;
        return;
    }
    tabs.removeNodeAtIndex(activeTab);
}

void Window::moveActiveTabTo(int index) 
{
    if(activeTab != -1) 
    {
        // TODO
        tabs.moveToIndex(activeTab, index-1);
        activeTab = index;
    }
}

void Window::changeActiveTabTo(int index) 
{
    // TODO
    if(index == -2147483648)
    {
        activeTab = tabs.getSize() -1;
    }
    if(index<0) return;
    if(activeTab != -1)
    {
        if(index >= tabs.getSize()) return;
        activeTab = index;
    }
}


void Window::addTab(Node<Tab> &tab) 
{
    // TODO
    tabs.append(tab.data);
    if(activeTab == -1) activeTab = 0;
}

void Window::print() 
{
    if(tabs.isEmpty()) std::cout << "Window is empty" << std::endl;
    else std::cout << "The active tab is tab " << activeTab << std::endl;
    tabs.print();
}