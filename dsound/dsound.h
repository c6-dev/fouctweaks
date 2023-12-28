#pragma once

#include <dsound.h>

#include "Logging.h"
#include "types.h"
#include "SafeWrite.h"
#include "patches.h"

typedef HRESULT(WINAPI *DirectSoundEnumerateAProc)(LPDSENUMCALLBACKA, LPVOID);

