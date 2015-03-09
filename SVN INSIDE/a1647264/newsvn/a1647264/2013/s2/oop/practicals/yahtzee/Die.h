#ifndef DIE_H
#define DIE_H

class Die {
	public:
		Die();
		Die(unsigned int face);
		~Die();
		
		unsigned int getFace() const;
		void roll();
		
	private:
		int m_face;
};

#endif
