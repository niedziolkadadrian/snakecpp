#ifndef STATES_H
#define STATES_H
class States
{
	
public:
	virtual void Initialize()=0;
	virtual void Inputs()=0;
	virtual void Update()=0;
	virtual void Draw()=0;

	virtual void Pause()=0;
	virtual void Resume()=0;
};
#endif
