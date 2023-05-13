#include "Struct.h"
void DestructConversations(conversation ** convers, int &size)
{
    delete [] (*convers);
}