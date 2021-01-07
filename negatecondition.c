
#include <time.h>
#include <setjmp.h>
#include <ctype.h>

#include "lapi.h"
#include "lauxlib.h"
#include "lcode.h"
#include "lctype.h"
#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "llex.h"
#include "llimits.h"
#include "lmem.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lopnames.h"
#include "lparser.h"
#include "lprefix.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "luaconf.h"
#include "lua.h"
#include "lualib.h"
#include "lundump.h"
#include "lvm.h"
#include "lzio.h"



extern Instruction * getjumpcontrol(FuncState *, int);

static void negatecondition (FuncState *fs, expdesc *e) {
  Instruction *pc = getjumpcontrol(fs, e->u.info);
  ((void)0);

  ((*pc) = (((*pc)&(~((~((~(Instruction)0)<<(1)))<<(((0 + 7) + 8))))) | ((((Instruction)((((((int)((((*pc)>>(((0 + 7) + 8))) & ((~((~(Instruction)0)<<(1)))<<(0))))))) ^ 1)))<<((0 + 7) + 8))&((~((~(Instruction)0)<<(1)))<<(((0 + 7) + 8))))));
}