#ifndef MEMORY_CPP_VIGNETTES_RANDOM_SELECTOR_H
#define MEMORY_CPP_VIGNETTES_RANDOM_SELECTOR_H

#include <vector>

class VignettesRandomSelector
{
private:
	std::vector< std::size_t > completeIndexes;

public:
	explicit VignettesRandomSelector(std::size_t maximumPair);
	~VignettesRandomSelector() = default;
	VignettesRandomSelector( const VignettesRandomSelector& ) = default;
	VignettesRandomSelector& operator= ( const VignettesRandomSelector& ) = default;
	VignettesRandomSelector( VignettesRandomSelector&& ) = default;
	VignettesRandomSelector& operator= ( VignettesRandomSelector&& ) = default;
	
	std::size_t size() const;//Return the real used pair number during the game
	std::size_t getValidIndex(std::size_t arrayIndex) const;//To get a used index in the 'finalIndexes' vector
	
private:
	void fillFullCollection();
	void shuffleFullCollection();
};

#endif //MEMORY_CPP_VIGNETTES_RANDOM_SELECTOR_H