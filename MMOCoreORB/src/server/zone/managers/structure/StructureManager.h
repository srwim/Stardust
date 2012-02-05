/*
 *	server/zone/managers/structure/StructureManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef STRUCTUREMANAGER_H_
#define STRUCTUREMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneProcessServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObject;

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {

class Deed;

} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed;

namespace server {
namespace zone {
namespace objects {
namespace structure {

class StructureObject;

} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {

class Deed;

} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed;

#include "server/zone/managers/templates/TemplateManager.h"

#include "server/zone/templates/tangible/SharedStructureObjectTemplate.h"

#include "server/zone/templates/tangible/SharedBuildingObjectTemplate.h"

#include "server/zone/templates/tangible/SharedInstallationObjectTemplate.h"

#include "engine/core/ManagedService.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/log/Logger.h"

#include "system/thread/Thread.h"

#include "system/util/SortedVector.h"

namespace server {
namespace zone {
namespace managers {
namespace structure {

class StructureManager : public ManagedService {
public:
	StructureManager(Zone* zne, ZoneProcessServer* proc);

	void initialize();

	int placeStructureFromDeed(CreatureObject* creature, Deed* deed, float x, float y, int angle);

	StructureObject* placeStructure(CreatureObject* creature, const String& structureTemplatePath, float x, float y, int angle);

	int destroyStructure(StructureObject* structureObject);

	int redeedStructure(CreatureObject* creature);

	int declareResidence(CreatureObject* player, StructureObject* structureObject);

	String getTimeString(unsigned int timestamp);

	SceneObject* getInRangeParkingGarage(SceneObject* obj, int range = 64);

	void reportStructureStatus(CreatureObject* creature, StructureObject* structure);

	void promptNameStructure(CreatureObject* creature, StructureObject* structure, TangibleObject* object);

	void promptManageMaintenance(CreatureObject* creature, StructureObject* structure, bool allowWithdrawal = true);

	void promptDeleteAllItems(CreatureObject* creature, StructureObject* structure);

	void promptFindLostItems(CreatureObject* creature, StructureObject* structure);

	void moveFirstItemTo(CreatureObject* creature, StructureObject* structure);

	void promptPayUncondemnMaintenance(CreatureObject* creature, StructureObject* structure);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	StructureManager(DummyConstructorParameter* param);

	virtual ~StructureManager();

	String _return_getTimeString;

	friend class StructureManagerHelper;
};

} // namespace structure
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::structure;

namespace server {
namespace zone {
namespace managers {
namespace structure {

class StructureManagerImplementation : public ManagedServiceImplementation, public Logger {
	ManagedWeakReference<Zone* > zone;

	ManagedReference<ZoneProcessServer* > server;

	Reference<TemplateManager* > templateManager;

public:
	StructureManagerImplementation(Zone* zne, ZoneProcessServer* proc);

	StructureManagerImplementation(DummyConstructorParameter* param);

	void initialize();

private:
	void loadPlayerStructures();

public:
	int placeStructureFromDeed(CreatureObject* creature, Deed* deed, float x, float y, int angle);

	StructureObject* placeStructure(CreatureObject* creature, const String& structureTemplatePath, float x, float y, int angle);

	int destroyStructure(StructureObject* structureObject);

	int redeedStructure(CreatureObject* creature);

	int declareResidence(CreatureObject* player, StructureObject* structureObject);

	String getTimeString(unsigned int timestamp);

	SceneObject* getInRangeParkingGarage(SceneObject* obj, int range = 64);

	void reportStructureStatus(CreatureObject* creature, StructureObject* structure);

	void promptNameStructure(CreatureObject* creature, StructureObject* structure, TangibleObject* object);

	void promptManageMaintenance(CreatureObject* creature, StructureObject* structure, bool allowWithdrawal = true);

	void promptDeleteAllItems(CreatureObject* creature, StructureObject* structure);

	void promptFindLostItems(CreatureObject* creature, StructureObject* structure);

	void moveFirstItemTo(CreatureObject* creature, StructureObject* structure);

	void promptPayUncondemnMaintenance(CreatureObject* creature, StructureObject* structure);

	WeakReference<StructureManager*> _this;

	operator const StructureManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~StructureManagerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class StructureManager;
};

class StructureManagerAdapter : public ManagedServiceAdapter {
public:
	StructureManagerAdapter(StructureManager* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	int placeStructureFromDeed(CreatureObject* creature, Deed* deed, float x, float y, int angle);

	StructureObject* placeStructure(CreatureObject* creature, const String& structureTemplatePath, float x, float y, int angle);

	int destroyStructure(StructureObject* structureObject);

	int redeedStructure(CreatureObject* creature);

	int declareResidence(CreatureObject* player, StructureObject* structureObject);

	String getTimeString(unsigned int timestamp);

	SceneObject* getInRangeParkingGarage(SceneObject* obj, int range);

	void reportStructureStatus(CreatureObject* creature, StructureObject* structure);

	void promptNameStructure(CreatureObject* creature, StructureObject* structure, TangibleObject* object);

	void promptManageMaintenance(CreatureObject* creature, StructureObject* structure, bool allowWithdrawal);

	void promptDeleteAllItems(CreatureObject* creature, StructureObject* structure);

	void promptFindLostItems(CreatureObject* creature, StructureObject* structure);

	void moveFirstItemTo(CreatureObject* creature, StructureObject* structure);

	void promptPayUncondemnMaintenance(CreatureObject* creature, StructureObject* structure);

protected:
	String _param1_placeStructure__CreatureObject_String_float_float_int_;
};

class StructureManagerHelper : public DistributedObjectClassHelper, public Singleton<StructureManagerHelper> {
	static StructureManagerHelper* staticInitializer;

public:
	StructureManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<StructureManagerHelper>;
};

} // namespace structure
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::structure;

#endif /*STRUCTUREMANAGER_H_*/
