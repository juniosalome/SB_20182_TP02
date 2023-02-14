/*
 * constantes.h
 *
 */

#ifndef SRC_MONTADOR_CONSTANTES_H_
#define SRC_MONTADOR_CONSTANTES_H_

//Modo de exibicao
char *modo;

//arquivo entrada
char *entrada;

//arquivo saida
char *saida;

/*
 * Estrutura que o mantem uma tabela de valores de opcode
 * */
enum OPCODE{
	opcode_ADD = 1,
	opcode_SUB = 2,
	opcode_AND = 3,
	opcode_OR = 4,
	opcode_XOR = 5,
	opcode_NOT = 6,
	opcode_JUMP = 7,
	opcode_JZ = 8,
	opcode_JNZ = 9,
	opcode_JN = 10,
	opcode_JNN = 11,
	opcode_PUSH = 12,
	opcode_POP = 13,
	opcode_CALL = 14,
	opcode_LOAD = 15,
	opcode_STORE = 16,
	opcode_READ = 17,
	opcode_WRITE = 18,
	opcode_COPY = 19,
	opcode_RET = 20,
	opcode_HALT = 21,
	opcode_WORD = 22,
	opcode_END = 23
};

#endif /* SRC_MONTADOR_CONSTANTES_H_ */
