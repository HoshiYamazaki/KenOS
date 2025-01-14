#ifndef _IDT_H
#define _IDT_H
#include <stddef.h>

struct idt_entry{
    unsigned short base_lo;
    unsigned short sel;        
    unsigned char always0;    
    unsigned char flags;       
    unsigned short base_hi;
} __attribute__((packed));

struct idt_ptr{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

extern struct idt_entry idt[256];
extern struct idt_ptr idtp;
extern void idt_load();

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_install();

#endif