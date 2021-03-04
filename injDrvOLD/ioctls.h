#pragma once
#include "definitions.h"
#define ioctl_read_memory CTL_CODE(FILE_DEVICE_UNKNOWN, 0x808, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define ioctl_write_memory CTL_CODE(FILE_DEVICE_UNKNOWN, 0x809, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define ioctl_get_module_base CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS) 
#define ioctl_protect_virutal_memory CTL_CODE(FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS) 
#define ioctl_allocate_virtual_memory CTL_CODE(FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define ioctl_free_memory CTL_CODE(FILE_DEVICE_UNKNOWN + 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)


typedef struct _set_module_information
{
	ULONG pid;
	wchar_t sz_name[32];
} set_module_information, * pset_module_information;

typedef struct _k_get_base_module_request {
	ULONG pid;
	ULONGLONG handle;
	WCHAR name[260];
} k_get_base_module_request, *pk_get_base_module_request;

typedef struct _k_rw_request {
	ULONG pid;
	ULONGLONG src;
	ULONGLONG dst;
	ULONGLONG size;
} k_rw_request, *pk_rw_request;

typedef struct _REQUEST_FREE {
	ULONG pid;
	ULONGLONG address;
} REQUEST_FREE, * PREQUEST_FREE;

typedef struct _k_alloc_mem_request {
	ULONG pid, allocation_type, protect;
	ULONGLONG addr;
	SIZE_T size;
} k_alloc_mem_request, *pk_alloc_mem_request;

typedef struct _k_protect_mem_request {
	ULONG pid, protect;
	ULONGLONG addr;
	SIZE_T size;
} k_protect_mem_request, *pk_protect_mem_request;


typedef struct _free_memory
{
	ULONG pid;
	ULONGLONG address;
} free_memory, * pfree_memory;






typedef struct _ALLOCATE_FREE_MEMORY
{
	ULONGLONG base;             // Region base address
	ULONGLONG size;             // Region size
	ULONG     pid;              // Target process id
	ULONG     protection;       // Memory protection for allocation
	ULONG     type;             // MEM_RESERVE/MEM_COMMIT/MEM_DECOMMIT/MEM_RELEASE
	BOOLEAN   allocate;         // TRUE if allocation, FALSE is freeing
	BOOLEAN   physical;         // If set to TRUE, physical pages will be directly mapped into UM space
} ALLOCATE_FREE_MEMORY, * PALLOCATE_FREE_MEMORY;


typedef struct _ALLOCATEE_FREE_MEMORY
{
	ULONGLONG base;             // Region base address
	ULONGLONG size;             // Region size
	ULONG     pid;              // Target process id
	ULONG     protection;       // Memory protection for allocation
	ULONG     type;             // MEM_RESERVE/MEM_COMMIT/MEM_DECOMMIT/MEM_RELEASE
	BOOLEAN   allocate;         // TRUE if allocation, FALSE is freeing
	BOOLEAN   physical;         // If set to TRUE, physical pages will be directly mapped into UM space
} ALLOCATEE_FREE_MEMORY, * PALLOCATEE_FREE_MEMORY;



typedef struct _get_module_information
{
	ULONGLONG base_image;
	ULONGLONG size_of_image;
} get_module_information, * pget_module_information;




typedef struct _ALLOCATE_FREE_MEMORY_RESULT
{
	ULONGLONG address;          // Address of allocation
	ULONGLONG size;             // Allocated size
} ALLOCATE_FREE_MEMORY_RESULT, * PALLOCATE_FREE_MEMORY_RESULT;






