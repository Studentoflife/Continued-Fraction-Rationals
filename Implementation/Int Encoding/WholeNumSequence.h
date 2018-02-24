#ifndef WHOLENUMSEQUENCE_H
#define WHOLENUMSEQUENCE_H

#include "BitSequence.h"
#include <cstddef>

//using namespace BitSequence_NS;

template <bool ENDIAN>
class WholeNumSequence {
public:
	typedef unsigned long long wnum_t;
private:
	BitSequence<ENDIAN,false> bseq;
	
	struct {
		unsigned int a_nm1 : (CHAR_BIT-1);
		bool a_nm2_l3 : 1;
	} track_prev;
	inline bool rho_leq_3d4() const;
	inline void update_rho(wnum_t n);

public:
	std::size_t encoding_bitlength(wnum_t n);

	explicit WholeNumSequence();
	explicit WholeNumSequence(BitSequence<ENDIAN,false> bits);
	void init(BitSequence<ENDIAN,false> bits);
	BitSequence<ENDIAN,false> get_bit_sequence();

	bool has_next() const;
	void skip_next();
	bool fits_next(const wnum_t& value) const;

	// TODO make >>, << throw exceptions, get/set_next not check
	bool peek_next(wnum_t& value) const;
	bool get_next(wnum_t& value);
	bool set_next(wnum_t value);

	WholeNumSequence& operator<<(const wnum_t& u);
	WholeNumSequence& operator>>(wnum_t& u);
};

#include "WholeNumSequence.tpp"

#endif
