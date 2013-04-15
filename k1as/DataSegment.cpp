//**************************************************************************************************************
// CLASS: cDataSegment
//
// DESCRIPTION
// See comments in DataSegment.hpp.
//
// AUTHOR INFORMATION
// Kevin R. Burger
//
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:	  http://kevin.floorsoup.com
//**************************************************************************************************************
#include "DataSegment.hpp"

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// IMPORTANT:
// Study this code to see how the base class ctor gets called in the member initialization list. In C++, the
// base class default ctor will be called automatically from the member initialization list, e.g., if you write
// this,
//
// cDataSegment::cDataSegment(tAddress const pAddress)
// {
// }
//
// The compiler generates this,
//
// cDataSegment::cDataSegment(tAddress const pAddress)
//	   : cSegment()	 -- Calls the base class default ctor automatically.
// {
// }
//
// If you wish to call a different ctor, you can, but you have to call it explicitly, AND, it has to be called
// from the member initialization list (i.e., not in the function body).
//--------------------------------------------------------------------------------------------------------------
cDataSegment::cDataSegment(tAddress const pAddress) :
	cSegment(pAddress)  // Calls cSegment::cSegment(tAddress const) rather than cSegment::cSegment()
{
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//
// IMPORTANT:
// Make sure you study this code to see how the copy constructor works for a derived class.
//--------------------------------------------------------------------------------------------------------------
cDataSegment::cDataSegment(cDataSegment const& pDataSegment) :
	cSegment(pDataSegment),	   // Call the base class ctor to allow it to copy its data members of pDataSegment
	mVars(pDataSegment.mVars)  // Copy the derived class data members of pDataSegment to this object
{
}

//--------------------------------------------------------------------------------------------------------------
// Add()
//
// REMARK
// See http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html for a std::map tutorial.
// The general way to insert or add a value to a std::map is to write: mapObj[key] = value;
//--------------------------------------------------------------------------------------------------------------
void cDataSegment::Add(cVariable const& pVariable)
{
	mVars[pVariable.Name()] = pVariable;
}

//--------------------------------------------------------------------------------------------------------------
// Contents()
//
// DESCRIPTION
// Returns the contents of the data segment in the binary format to which it will be written to the binary file.
// See the lab project document for a discussion of the binary format of the data segment.
//
// REMARK
// See http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html for a std::map tutorial. In particular, study how an
// "iterator" can be created to iterate over the elements of a std::map.
//--------------------------------------------------------------------------------------------------------------
tByte const *cDataSegment::Contents() const
{
	// Dynamically allocate a 1D array of tWords large enough to store the initial values of all of the
	// Variables. The size() function on a map object returns the number of elements in the map.
	tWord *contents = new tWord[mVars.size()];

	// Create a constant iterator over the map mVars. The iterator is const because we are not going to
	// be modifying the Variable objects as we iterate over them. If you want to create a non-const
	// iterator then you would write: std::map<string, cVariable>::iterator it = mVars.begin();
	std::map<string, cVariable>::const_iterator it = mVars.begin();

	// Iterate over each element of the map.
	for (unsigned varNum = 0; it != mVars.end(); ++it, ++varNum) {

		// 'it' is a pointer to a map element. We retrieve the value of this map element by accessing the
		// 'second' data member of the iterator (the 'first' data member of the map element would be the key).
		// Since the map values are cVariables, it->second is a cVariable object (it->first is a string object).
		cVariable variable = it->second;

		// Get the initial value of the variable. Note: the initial value is stored in 2's complement notation
		// (to handle negative initial values) so the data type returned is tInt32 rather than tWord (tWord is
		// an unsigned data type).
		tInt32 initValue = variable.InitValue();

		// Put the initial value of the variable into the contents array at the proper index.
		contents[varNum] = initValue;
	}

	// Return the dynamically allocated array type casted as an array of constant tBytes. Note that the
	// Binary::Write() function deallocates this array.
	return reinterpret_cast<tByte const *>(contents);
}

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes this cDataSegment object a copy of pDataSegment.
//--------------------------------------------------------------------------------------------------------------
void cDataSegment::Copy(cDataSegment const& pDataSegment)
{
	// Call the base class (cSegment) Copy() function to copy the data members inherited from cSegment.
	cSegment::Copy(pDataSegment);

	// Copy the derived class (cDataSegment) data members. This assignment invokes std::map:::operator=()
	// on mVars and passes pDataSegment.mVars as the parameter.
	mVars = pDataSegment.mVars;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
cDataSegment& cDataSegment::operator=(cDataSegment const& pDataSegment)
{
	if (this != &pDataSegment) Copy(pDataSegment);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// Size()
//
// DESCRIPTION:
// Reads the number of bytes the data segment will consume when written to the binary file. Each variable is
// 4 bytes in the binary and the data segment header takes 9 bytes. Therefore the size of the data segment is
// 9 + 4 * (number of variables).
//--------------------------------------------------------------------------------------------------------------
tUint32 cDataSegment::Size() const
{
	return 9 + 4 * mVars.size();
}
