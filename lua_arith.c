
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



extern void luaO_arith(lua_State *, int, const TValue *, const TValue *, StkId);

extern void lua_arith (lua_State *L, int op) {
  ((void) 0);
  if (op != 12 && op != 13)
    ((void)L, ((void)0));
  else {
    ((void)L, ((void)0));
    { TValue *io1=((&(L->top)->val)); const TValue *io2=((&(L->top - 1)->val)); io1->value_ = io2->value_; ((io1)->tt_=(io2->tt_)); ((void)L, ((void)0)); ((void)0); };
    {L->top++; ((void)L, ((void)0));};
  }

  luaO_arith(L, op, (&(L->top - 2)->val), (&(L->top - 1)->val), L->top - 2);
  L->top--;
  ((void) 0);
}