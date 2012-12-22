#include "Jockey.h"

JockeyEvents& getJockeyEvents()
{
	static JockeyEvents* events = new JockeyEvents;
	return *events;
}
