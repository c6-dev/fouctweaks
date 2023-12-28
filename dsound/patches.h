#pragma once
#include "ModUtils/Patterns.h"
#include "calls.h"
UInt32 callAdr = NULL;
UInt32 jumpAddr = NULL;

__declspec(naked) void SkipLauncher() {
	__asm {
		call callAdr
		add esp, 4
		mov eax, dword ptr ds:[ebp+10]
		mov ebx, 1
		jmp jumpAddr
	}
}
void writePatches() {
		auto skipLauncher = hook::pattern("C2 10 00 83 F8 4E").get_first(-19);
		callAdr = (UInt32)hook::pattern("6A 0C 68 0D 04 00 00 53 33 FF").get_first(-48);
		jumpAddr = (UInt32)hook::pattern("68 F0 00 00 00 68 25 04 00").get_first(-7);
		WriteRelJump((UInt32)skipLauncher, (UInt32)SkipLauncher);

}