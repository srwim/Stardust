/*
 *	server/zone/objects/tangible/terminal/Terminal.cpp generated by engine3 IDL compiler 0.61
 */

#include "Terminal.h"

#include "server/zone/Zone.h"

/*
 *	TerminalStub
 */

Terminal::Terminal() : TangibleObject(DummyConstructorParameter::instance()) {
	TerminalImplementation* _implementation = new TerminalImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

Terminal::Terminal(DummyConstructorParameter* param) : TangibleObject(param) {
}

Terminal::~Terminal() {
}


void Terminal::initializeTransientMembers() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

bool Terminal::isTerminal() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isTerminal();
}

bool Terminal::isGuildTerminal() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isGuildTerminal();
}

DistributedObjectServant* Terminal::_getImplementation() {
	return _impl;}

void Terminal::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	TerminalImplementation
 */

TerminalImplementation::TerminalImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


TerminalImplementation::~TerminalImplementation() {
}


void TerminalImplementation::finalize() {
}

void TerminalImplementation::_initializeImplementation() {
	_setClassHelper(TerminalHelper::instance());

	_serializationHelperMethod();
}

void TerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Terminal*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TerminalImplementation::_getStub() {
	return _this;
}

TerminalImplementation::operator const Terminal*() {
	return _this;
}

void TerminalImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void TerminalImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void TerminalImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void TerminalImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void TerminalImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void TerminalImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void TerminalImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void TerminalImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Terminal");

}

TerminalImplementation::TerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/Terminal.idl(54):  		Logger.setLoggingName("Terminal");
	Logger::setLoggingName("Terminal");
}

bool TerminalImplementation::isTerminal() {
	// server/zone/objects/tangible/terminal/Terminal.idl(60):  		return true;
	return true;
}

bool TerminalImplementation::isGuildTerminal() {
	// server/zone/objects/tangible/terminal/Terminal.idl(64):  		return false;
	return false;
}

/*
 *	TerminalAdapter
 */

TerminalAdapter::TerminalAdapter(TerminalImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* TerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertBoolean(isTerminal());
		break;
	case 8:
		resp->insertBoolean(isGuildTerminal());
		break;
	default:
		return NULL;
	}

	return resp;
}

void TerminalAdapter::initializeTransientMembers() {
	((TerminalImplementation*) impl)->initializeTransientMembers();
}

bool TerminalAdapter::isTerminal() {
	return ((TerminalImplementation*) impl)->isTerminal();
}

bool TerminalAdapter::isGuildTerminal() {
	return ((TerminalImplementation*) impl)->isGuildTerminal();
}

/*
 *	TerminalHelper
 */

TerminalHelper* TerminalHelper::staticInitializer = TerminalHelper::instance();

TerminalHelper::TerminalHelper() {
	className = "Terminal";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void TerminalHelper::finalizeHelper() {
	TerminalHelper::finalize();
}

DistributedObject* TerminalHelper::instantiateObject() {
	return new Terminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* TerminalHelper::instantiateServant() {
	return new TerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TerminalAdapter((TerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

