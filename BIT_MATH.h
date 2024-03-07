#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/*#define SET_BIT(REG,BIT_NUM)                        REG|=(1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM)                        REG&=(~(1<<BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)                        REG^=(1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM)                        ((REG>>BIT_NUM)&1)*/

#define		ASSIGN_PORT(Var , Val)	Var = Val
#define		SET_BIT(Var , BitNo)	Var = Var | (1 << BitNo)
#define		CLEAR_BIT(Var , BitNo)	Var = Var & ~(1 << BitNo)
#define		GET_BIT(Var , BitNo)	( (Var >> BitNo) & 1 )
#define		TOGGLE_BIT(Var , BitNo)	Var = Var ^ (1 << BitNo)


#endif