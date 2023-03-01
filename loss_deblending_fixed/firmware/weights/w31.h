//Numpy array shape [256, 518]
//Min -1.023340463638
//Max 1.155738353729
//Number of zeros 0

#ifndef W31_H_
#define W31_H_

#ifdef __INTELFPGA_COMPILER__
hls_bankwidth(2)
hls_numbanks(4096)
hls_max_replicates(1)
hls_memory_impl("BLOCK_RAM")
#endif

#endif