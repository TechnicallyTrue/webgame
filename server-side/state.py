# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.2
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _state
else:
    import _state

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


class Thing(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def setX(self, x):
        return _state.Thing_setX(self, x)

    def getX(self):
        return _state.Thing_getX(self)

    def __init__(self):
        _state.Thing_swiginit(self, _state.new_Thing())
    __swig_destroy__ = _state.delete_Thing

# Register Thing in _state:
_state.Thing_swigregister(Thing)

class Item(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    itemName = property(_state.Item_itemName_get, _state.Item_itemName_set)

    def interact(self, action):
        return _state.Item_interact(self, action)
    description = property(_state.Item_description_get, _state.Item_description_set)
    isVisible = property(_state.Item_isVisible_get, _state.Item_isVisible_set)

    def __init__(self, name):
        _state.Item_swiginit(self, _state.new_Item(name))
    __swig_destroy__ = _state.delete_Item

# Register Item in _state:
_state.Item_swigregister(Item)

class Room(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    roomName = property(_state.Room_roomName_get, _state.Room_roomName_set)
    adjRooms = property(_state.Room_adjRooms_get, _state.Room_adjRooms_set)
    roomItems = property(_state.Room_roomItems_get, _state.Room_roomItems_set)

    def describe(self):
        return _state.Room_describe(self)

    def __init__(self, name):
        _state.Room_swiginit(self, _state.new_Room(name))
    __swig_destroy__ = _state.delete_Room

# Register Room in _state:
_state.Room_swigregister(Room)

class GameState(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    frontUnlocked = property(_state.GameState_frontUnlocked_get, _state.GameState_frontUnlocked_set)

    def __init__(self):
        _state.GameState_swiginit(self, _state.new_GameState())
    __swig_destroy__ = _state.delete_GameState

# Register GameState in _state:
_state.GameState_swigregister(GameState)


def test():
    return _state.test()


