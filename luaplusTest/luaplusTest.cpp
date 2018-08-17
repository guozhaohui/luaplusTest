#include <stdio.h>
#include <stdlib.h>

#include <LuaPlus.h>

using namespace LuaPlus;

class MultiObject
{
public:
	MultiObject(int num):
	m_num(num)
	{
	}

	int Print(LuaState* state)
	{
		printf("%d\n", m_num);
		return 0;
	}

	void Print2(int num)
	{
		printf("%d %d\n", m_num, num);
	}
protected:
	int m_num;
};

static int LS_AddPrint(LuaState* state)
{
	LuaStack args(state);
	assert(args[1].IsNumber());
	assert(args[2].IsNumber());
	assert(args[3].IsString());

	lua_Number add = args[1].GetNumber() + args[2].GetNumber();
	printf("%f_%s\n", add, args[3].GetString());

	return 0;
}

/**
 * call cpp functions from lua code
 */
void call_cpp_functions( LuaState* state )
{
	/* create meta table */
	LuaObject metaTableObj = state->GetGlobals().CreateTable("MultiObjectMetaTable");
	metaTableObj.SetObject("__index", metaTableObj);
	metaTableObj.RegisterObjectFunctor("Print", &MultiObject::Print);

	/* c++ objects with meta table */
	MultiObject obj1(10);
	LuaObject obj1Obj = state->BoxPointer(&obj1);
	obj1Obj.SetMetatable(metaTableObj);
	state->GetGlobals().SetObject("obj1", obj1Obj);

	MultiObject obj2(20);
	LuaObject obj2Obj = state->BoxPointer(&obj2);
	obj2Obj.SetMetatable(metaTableObj);
	state->GetGlobals().SetObject("obj2", obj2Obj);

	state->DoString("obj1:Print()");
	state->DoString("obj2:Print()");

	/* user data with meta table */
	LuaObject table1Obj = state->GetGlobals().CreateTable("table1");
	table1Obj.SetLightUserdata("__object", &obj1);
	table1Obj.SetMetatable(metaTableObj);

	LuaObject table2Obj = state->GetGlobals().CreateTable("table2");
	table2Obj.SetLightUserdata("__object", &obj2);
	table2Obj.SetMetatable(metaTableObj);

	state->DoString("table1:Print()");
	state->DoString("table2:Print()");

	/* use RegisterObjectDirect */
	metaTableObj.RegisterObjectDirect("Print2", (MultiObject*)0, &MultiObject::Print2);
	state->DoString("obj1:Print2(5)");
	state->DoString("table2:Print2(15)");

	/* use RegisterDirect */
	LuaObject globalObj = state->GetGlobals();
	MultiObject obj3(30);
	globalObj.RegisterDirect("obj3_Print2", obj3, &MultiObject::Print2);
	state->DoString("obj3_Print2(5)");

	/* use Register and call via LuaStack */
	state->GetGlobals().Register("AddPrint", LS_AddPrint);
	state->DoString("AddPrint(5, 10, \"Hello\")");
	int top = state->GetTop();
	LuaObject addPrintObj = state->GetGlobals()["AddPrint"];
	LuaCall call = addPrintObj;
	call << 5 << 10 << "Hello" << LuaRun();
	printf("start_top: %d, end_top: %d\n", top, state->GetTop());
}

/**
 * call lua functions from cpp code
 */
void call_lua_functions( LuaState* state )
{
	/* use LuaCall */
	state->DoString("function Add(x, y) return x + y end");
	//LuaFunction<float> AddFunc(state, "Add");
	//printf("Add: %f\n", AddFunc(2, 7));
	LuaObject addObj = state->GetGlobal("Add");
	LuaCall addCall = addObj;
	LuaObject retAddObj = addCall << 2 << 7 << LuaRun();
	printf("Add:%d\n", retAddObj.GetInteger());

	state->DoString("function PrintImp(str) print(str) end");
	//LuaFunction<void> PrintFunc(state, "PrintImp");
	//PrintFunc("Hello World!");
	LuaObject printObj = state->GetGlobal("PrintImp");
	LuaCall printCall = printObj;
	printCall << "Hello World!" << LuaRun();

}

int main()
{
	LuaState* state = LuaState::Create();
	state->OpenLibs();  /* for using print function .etc in lua code */

	call_cpp_functions( state ); 
	call_lua_functions( state );

	LuaState::Destroy( state );

	return 0;
}
