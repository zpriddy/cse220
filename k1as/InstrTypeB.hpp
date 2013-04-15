//**************************************************************************************************************
// CLASS: cInstrTypeB (derived from cInstr)
//
// DESCRIPTION
// A type B instruction is a branch instruction. Each branch instruction encodes the branch target address in
// the address field of the instruction. All branch instructions are instances of this class.
//
// Note that cInstTypeB is derived from cInstr.
//
// AUTHOR INFORMATION
// Kevin R. Burger [KRB]
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
#ifndef INSTRTYPEB_HPP
#define INSTRTYPEB_HPP

#include <string>
using std::string;

#include "Instr.hpp"
#include "Label.hpp"

//==============================================================================================================
// CLASS: cInstrTypeB
//==============================================================================================================
class cInstrTypeB : public cInstr {

public:
	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//==========================================================================================================

	//----------------------------------------------------------------------------------------------------------
	// Default ctor.
	//----------------------------------------------------------------------------------------------------------
	cInstrTypeB();

	//----------------------------------------------------------------------------------------------------------
	// Constructor. A type B instruction has a mnemonic and a branch target label.
	//----------------------------------------------------------------------------------------------------------
	cInstrTypeB(string const& pMnemonic, cLabel const& pLabel);

	//----------------------------------------------------------------------------------------------------------
	// Copy ctor.
	//----------------------------------------------------------------------------------------------------------
	cInstrTypeB(cInstrTypeB const& pInstr);

	//----------------------------------------------------------------------------------------------------------
	// Virtual dtor.
	//----------------------------------------------------------------------------------------------------------
	virtual ~cInstrTypeB()
	{
	}

	//----------------------------------------------------------------------------------------------------------
	// Encode()
	//----------------------------------------------------------------------------------------------------------
	virtual void Encode();

	//----------------------------------------------------------------------------------------------------------
	// Label()
	//
	// DESCRIPTION
	// Accessor function for mLabel.
	//----------------------------------------------------------------------------------------------------------
	cLabel Label() const
	{
		return mLabel;
	}

	//----------------------------------------------------------------------------------------------------------
	// operator=()
	//----------------------------------------------------------------------------------------------------------
	cInstrTypeB& operator=(cInstrTypeB const& pInstr);

protected:
	//==========================================================================================================
	// PROTECTED FUNCTION MEMBERS
	//==========================================================================================================

	//----------------------------------------------------------------------------------------------------------
	// Copy()
	//----------------------------------------------------------------------------------------------------------
	void Copy(cInstrTypeB const& pInstr);

	//----------------------------------------------------------------------------------------------------------
	// Label(cLabel const&)
	//
	// DESCRIPTION
	// Mutator function for mLabel.
	//----------------------------------------------------------------------------------------------------------
	void Label(cLabel const& pLabel)
	{
		mLabel = pLabel;
	}

private:
	//==========================================================================================================
	// PRIVATE DATA MEMBERS:
	//==========================================================================================================
	cLabel mLabel;
};

#endif
