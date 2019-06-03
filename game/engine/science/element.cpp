#include "element.h"

std::ostream & operator<<(std::ostream & out, const Element & e)
{
	out << "Name: " << e.elementName << std::endl << "Type: " << elementTypeToString(e.elementType);
	return out;
}