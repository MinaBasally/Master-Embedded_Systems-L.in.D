> This is an STM32F103C6 Baremetal Software in which malloc() was used to perform a Dynamic Allocation.
> The Software toggles an LED using GPIOA-PIN(13).
> malloc() calls _sbrk().
> _sbrk() requires an Operating System to run on as it makes a system call.
> Thus, it is required to locally-implement _sbrk() in order to support malloc() in Embedded C as _sbrk() is not defined in The C Standard Library.
> All {*.h, *.c, *.s, *.ld & make} files were created and designed by myself.
> The Software was cross-compiled using YAGARTO-20121222_ARM_toolchain.
> A Simulation was done on Proteus for validation, and was recorded.



															From the author,
															  Mina Basally