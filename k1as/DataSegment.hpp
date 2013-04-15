//**************************************************************************************************************
// CLASS: DataSegment.hpp.
//
// DESCRIPTION
// Declares a class that maintains the information in the .DATA segment. In particular, stores a std::map
// with key = std::string and value = cVariable.
//
// Note that cDataSegment is derived from cSegment. The cSegment class stores a data member which is the address
// of the segment. The cDataSegment class adds a std::map which stores the cVariables of the data segment.
//
// REFERENCES
// 1. http://www.cplusplus.com/reference/stl/map
// 2. http://www.cprogramming.com/tutorial/stl/stlmap.html
// 3. http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html
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
#ifndef DATASEGMENT_HPP
#define DATASEGMENT_HPP

#include <map>
using std::map;

#include <string>
using std::string;

#include "Segment.hpp"
#include "Types.hpp"
#include "Variable.hpp"

//==============================================================================================================
// CLASS: cDataSegment
//
// IMPORTANT:
// Notice how to specify that cDataSegment is derived from cSegment. The "public" reserved word means that the
// members of the derived class (cDataSegment in this case) will have the same access level (public, protected,
// or private) as the members in the base class (cSegment in this case). For example,
//
// class Base {
// public:
//	  int mPub;
// protected:
//	  int mProt;
// private:
//	  mPriv;
// };
//
// class Derived : public Base {
//	   ...
// };
//
// void SomeFunction()	 -- obj.mPub is public
// {                     -- obj.mProt is protected
//	   Derived obj;  -- obj.mPriv is private
// }
//
// Compare this to protected inheritance. In this case, all public members of the base class are inherited as
// protected in the derived class. Private members of the base class remain private in the derived class.
//
// class Base {
// public:
//	  int mPub;
// protected:
//	  int mProt;
// private:
//	  mPriv;
// };
//
// class Derived : protected Base {
//	   ...
// };
//
// void SomeFunction()	  -- obj.mPub is protected
// {                      -- obj.mProt is protected
//	   Derived obj;   -- obj.mPriv is private
// }
//
// Lastly, there is private inheritance in which all members of the base class become private in the derived
// class.
//
// class Base {
// public:
//	  int mPub;
// protected:
//	  int mProt;
// private:
//	  mPriv;
// };
//
// class Derived : private Base {
//	   ...
// };
//
// void SomeFunction()	  -- obj.mPub is private
// {                      -- obj.mProt is private
//	   Derived obj;   -- obj.mPriv is private
// }
//==============================================================================================================
class cDataSegment : public cSegment {

public:
	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//==========================================================================================================

	//----------------------------------------------------------------------------------------------------------
	// Default ctor.
	//----------------------------------------------------------------------------------------------------------
	cDataSegment(tAddress const pAddress = 0);

	//----------------------------------------------------------------------------------------------------------
	// Copy ctor.
	//----------------------------------------------------------------------------------------------------------
	cDataSegment(cDataSegment const& pDataSegment);

	//----------------------------------------------------------------------------------------------------------
	// Dtor.
	//
	// REMARK
	// Note that the base class destructor will be called automatically, AFTER the body of this dtor is executed
	//
	// REMARK
	// I inline functions that do nothing.
	//----------------------------------------------------------------------------------------------------------
	~cDataSegment()
	{
	}

	//----------------------------------------------------------------------------------------------------------
	// Add()
	//
	// DESCRIPTION
	// Adds pVariable to the std::map mVars.
	//----------------------------------------------------------------------------------------------------------
	void Add(cVariable const& pVariable);

	//----------------------------------------------------------------------------------------------------------
	// Variable()
	//
	// DESCRIPTION
	// Retrieves the Variable with name pName from the std::map mVars.
	//
	// REMARK
	// This is essentially an accessor function for the mVars data member, so I inlined it.
	//----------------------------------------------------------------------------------------------------------
	cVariable Variable(string const& pName)
	{
		return mVars[pName];
	}

	//----------------------------------------------------------------------------------------------------------
	// Contents()
	//
	// REMARK
	// "tByte const *" states that this function returns a pointer to a constant tByte (or tBytes). In English,
	// this means that the "constant tBytes" to which this pointer points cannot be modified via the pointer.
	// They can be modified via a different pointer, but not by this one.
	//----------------------------------------------------------------------------------------------------------
	tByte const *Contents() const;

	//----------------------------------------------------------------------------------------------------------
	// Size()
	//----------------------------------------------------------------------------------------------------------
	tUint32 Size() const;

	//----------------------------------------------------------------------------------------------------------
	// operator=()
	//----------------------------------------------------------------------------------------------------------
	cDataSegment& operator=(cDataSegment const& pDataSegment);

protected:
	//==========================================================================================================
	// PROTECTED FUNCTION MEMBERS
	//==========================================================================================================

	//----------------------------------------------------------------------------------------------------------
	// Copy()
	//----------------------------------------------------------------------------------------------------------
	void Copy(cDataSegment const& pDataSegment);

private:
	//==========================================================================================================
	// PRIVATE DATA MEMBERS
	//==========================================================================================================

	// The cVariables in the data segment are stored in a map. "map" is a class in the C++ Standard Template
	// Library (STL). A map is also called a "dictionary". A map maps "keys" onto "values". In our map, named
	// mVars, the key is string and the value is a cVariable.

	map<string, cVariable> mVars;
};

#endif
