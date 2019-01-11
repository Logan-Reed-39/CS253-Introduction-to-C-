#include <cstdlib>
#include "ll.h" 

LinkedList::LinkedList(){
    m_pHead = nullptr;
}

void LinkedList::Link::initialize(unsigned int uiData, Link *pNext) {
    m_uiData = uiData;
    m_pNext = pNext;
}


bool LinkedList::insert(unsigned int uiData) {
    Link* new_link = new Link;

    new_link->initialize(uiData, m_pHead);
    m_pHead = new_link;
    
    delete new_link;

    return true;
}

bool LinkedList::remove(unsigned int &pData) {

    bool ret_val = false;

    if (m_pHead != nullptr) {
	Link *temp = m_pHead;
	m_pHead = m_pHead->m_pNext;
	pData = temp->m_uiData;

	ret_val = true;
    }

    return ret_val;
}
void LinkedList::print(unsigned int &pData) {

    cout << pData
}
