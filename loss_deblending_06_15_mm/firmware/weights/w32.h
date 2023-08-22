//Numpy array shape [256, 520]
//Min -3.600705862045
//Max 1.638890624046
//Number of zeros 0

#ifndef W32_H_
#define W32_H_

#ifdef __INTELFPGA_COMPILER__
hls_bankwidth(1)
hls_numbanks(512)
hls_max_replicates(1)
hls_memory_impl("BLOCK_RAM")
#endif

#endif