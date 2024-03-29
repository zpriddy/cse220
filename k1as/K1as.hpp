//**************************************************************************************************************
// CLASS: cK1as
//
// DESCRIPTION
//
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
#ifndef K1AS_HPP
#define K1AS_HPP

#include <string>
using std::string;

#include "Arg.hpp"
#include "DataSegment.hpp"
#include "Instr.hpp"
#include "Lex.hpp"
#include "TextSegment.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: cK1as
//==============================================================================================================
class cK1as {

public:
	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//==========================================================================================================

	//---------------------------------------------------------------------------------------------------------
	// Ctor.
	//---------------------------------------------------------------------------------------------------------
	cK1as(unsigned pArgc, char **pArgv);

	//---------------------------------------------------------------------------------------------------------
	// Dtor.
	//---------------------------------------------------------------------------------------------------------
	~cK1as()
	{
	}

private:
	//==========================================================================================================
	// PRIVATE FUNCTION MEMBERS
	//==========================================================================================================

	//---------------------------------------------------------------------------------------------------------
	// Perform pass pPass of the assembly.
	//---------------------------------------------------------------------------------------------------------
	void Assemble(unsigned const pPass);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a .DATA or .TEXT directive.
	//---------------------------------------------------------------------------------------------------------
	void AssembleDirective(string const& pDirective);

	//---------------------------------------------------------------------------------------------------------
	// Assembles an instruction
	//---------------------------------------------------------------------------------------------------------
	cInstr *AssembleInstr(string const& pMnemonic);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a type B instruction (branch).
	//---------------------------------------------------------------------------------------------------------
	cInstr *AssembleInstrTypeB(string const& pMnemonic);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a type N instruction (no arguments).
	//---------------------------------------------------------------------------------------------------------
	cInstr *AssembleInstrTypeN(string const& pMnemonic);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a type R instruction (register).
	//---------------------------------------------------------------------------------------------------------
	cInstr *AssembleInstrTypeR(string const& pMnemonic);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a type RI instruction (register, integer).
	//---------------------------------------------------------------------------------------------------------
	cInstr *AssembleInstrTypeRI(string const& pMnemonic);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a type RV instruction (register, variable).
	//---------------------------------------------------------------------------------------------------------
	cInstr *AssembleInstrTypeRV(string const& pMnemonic);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a label.
	//---------------------------------------------------------------------------------------------------------
	void AssembleLabel(string const& pName);

	//---------------------------------------------------------------------------------------------------------
	// Assembles a variable.
	//---------------------------------------------------------------------------------------------------------
	void AssembleVariable(string const& pName);

	//---------------------------------------------------------------------------------------------------------
	// Private copy ctor disallows copying of K1as objects.
	//---------------------------------------------------------------------------------------------------------
	cK1as(cK1as const&);

	//---------------------------------------------------------------------------------------------------------
	// Private operator=() disallows assignment of K1as objects.
	//---------------------------------------------------------------------------------------------------------
	cK1as& operator=(cK1as const&);

	//---------------------------------------------------------------------------------------------------------
	// Run()
	//---------------------------------------------------------------------------------------------------------
	void Run();

	//==========================================================================================================
	// PRIVATE DATA MEMBERS
	//==========================================================================================================
	cArg mArg;

	// The current address in the segment that is being assembled.
	tAddress mCurrAddr;

	// The data segment. The data segment stores Variable objects in a std::map.
	cDataSegment mDataSeg;

	// The lexical analyzer.
	cLex mLex;

	// The text segment. Stores Instr objects (in a std::vector) and Label objects (in a std::map).
	cTextSegment mTextSeg;
};

#endif
