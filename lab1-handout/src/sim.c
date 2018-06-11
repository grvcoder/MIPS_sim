#include <stdio.h>
#include "shell.h"

void (*norm_func[0x2C])();
void (*special_func[0x2C]) ();
void (*immediate_func[0x12])();

uint32_t cur_ins = 0x00;

#define OPCODE ((cur_ins >> 26) & 0x3F)
#define IMMEDIATE (cur_ins & 0x3F)
#define SPECIAL ((cur_ins >> 16) & 0x1F)




void special()
{
    if(SPECIAL < 0x2C)
        special_func[SPECIAL]();
    else
        nop();
}

void immediate()
{
    if(IMMEDIATE < 0x12)
        immediate_func[IMMEDIATE]();
    else
        nop();
}

void J()
{
    
}

void JAL()
{
}

void BEQ()
{
}

void BNE()
{
}

void BLEZ()
{
}

void BGTZ()
{
}

void ADDI()
{
}

void ADDIU()
{
}

void SLTI()
{
}

void SLTIU()
{
}

void ANDI()
{
}

void ORI()
{
}

void XORI()
{
}

void LUI()
{
}

void LB()
{
}

void LH()
{
}

void LW()
{
}


void LBU()
{
}

void LHU()
{
}

void SB()
{
}

void SH()
{
}

void SW()
{
}

void BLTZ()
{
}

void BGEZ()
{
}

void BLTZAL()
{
}

void BGEZAL()
{
}

void SLL()
{
}

void SRL()
{
}

void SRA()
{
}

void SLLV()
{
}

void SRLV()
{
}

void SRAV()
{
}

void JR()
{
}

void JALR()
{
}

void ADD()
{
}

void ADDU()
{
}

void SUB()
{
}

void SUBU()
{
}

void AND()
{
}

void OR()
{
}

void XOR()
{
}

void NOR()
{
}

void SLT()
{
}

void SLTU()
{
}

void MULT()
{
}

void MFHI()
{
}

void MFLO()
{
}

void MTHI()
{
}

void MTLO()
{
}

void MULTU()
{
}

void DIV()
{
}

void DIVU()
{
}

void SYSCALL()
{
}

void nop()
{
    
}

void process_instruction()
{
    cur_ins = mem_read_32(CURRENT_STATE.PC);
    
    norm_func[0x00] = special;
    norm_func[0x01] = immediate;
    norm_func[0x02] = J;
    norm_func[0x03] = JAL;
    norm_func[0x04] = BEQ;
    norm_func[0x05] = BNE;
    norm_func[0x06] = BLEZ;
    norm_func[0x07] = BGTZ;
    norm_func[0x08] = ADDI;
    norm_func[0x09] = ADDIU;
    norm_func[0x0A] = SLTI;
    norm_func[0x0B] = SLTIU;
    norm_func[0x0C] = ANDI;
    norm_func[0x0D] = ORI;
    norm_func[0x0E] = XORI;
    norm_func[0x0F] = LUI;
    norm_func[0x20] = LB;
    norm_func[0x21] = LH;
    norm_func[0x22] = nop;
    norm_func[0x23] = LW;
    norm_func[0x24] = LBU;
    norm_func[0x25] = LHU;
    norm_func[0x26] = nop;
    norm_func[0x27] = nop;
    norm_func[0x28] = SB;
    norm_func[0x29] = SH;
    norm_func[0x2A] = nop;
    norm_func[0x2B] = SW;

    for (int i=0x10; i< 0x20; i++)
        norm_func[i] = nop;
    
    special_func[0x00] = SLL;
    special_func[0x01] = nop;
    special_func[0x02] = SRL;
    special_func[0x03] = SRA;
    special_func[0x04] = SLLV;
    special_func[0x05] = nop;
    special_func[0x06] = SRLV;
    special_func[0x07] = SRAV;
    special_func[0x08] = JR;
    special_func[0x09] = JALR;
    special_func[0x0A] = nop;
    special_func[0x0B] = nop;
    special_func[0x0C] = SYSCALL;
    special_func[0x0D] = nop;
    special_func[0x0E] = nop;
    special_func[0x0F] = nop;
    special_func[0x10] = MFHI;
    special_func[0x11] = MTHI;
    special_func[0x12] = MFLO;
    special_func[0x13] = MTLO;
    special_func[0x14] = nop;
    special_func[0x15] = nop;
    special_func[0x16] = nop;
    special_func[0x17] = nop;
    special_func[0x18] = MULT;
    special_func[0x19] = MULTU;
    special_func[0x1A] = DIV;
    special_func[0x1B] = DIVU;
    special_func[0x1C] = nop;
    special_func[0x1D] = nop;
    special_func[0x1E] = nop;
    special_func[0x1F] = nop;
    special_func[0x20] = ADD;
    special_func[0x21] = ADDU;
    special_func[0x22] = SUB;
    special_func[0x23] = SUBU;
    special_func[0x24] = AND;
    special_func[0x25] = OR;
    special_func[0x26] = XOR;
    special_func[0x27] = NOR;
    special_func[0x28] = nop;
    special_func[0x29] = nop;
    special_func[0x2A] = SLT;
    special_func[0x2B] = SLTU;

    immediate_func[0x00] = BLTZ;
    immediate_func[0x01] = BGEZ;
    immediate_func[0x10] = BLTZAL;
    immediate_func[0x11] = BGEZAL;

    for(int i=0x02; i < 0x10; i++)
        immediate_func[i] = nop;

    if(OPCODE < 0x2C)
        norm_func[OPCODE]();

    else
        nop();

    NEXT_STATE.REGS[0x00] = 0x0;




}
