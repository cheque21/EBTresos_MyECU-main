import autosar

# =====================================================
# Workspace AUTOSAR
# =====================================================

ws = autosar.workspace("4.2.2")

# =====================================================
# Packages
# =====================================================

dataTypesPkg = ws.createPackage(
"DataTypes",
role="DataType"
)

portIfPkg = ws.createPackage(
"PortInterfaces",
role="PortInterface"
)

componentPkg = ws.createPackage(
"ComponentTypes",
role="ComponentType"
)

# =====================================================
# Base Type
# =====================================================

baseTypes = dataTypesPkg.createSubPackage("BaseTypes")

baseTypes.createSwBaseType(
"uint16",
16,
nativeDeclaration="uint16"
)

# =====================================================
# Sender Receiver Interface
# =====================================================

portIfPkg.createSenderReceiverInterface(
"BrakePosition_I",
autosar.element.DataElement(
"BrakePosition",
"/DataTypes/BaseTypes/uint16"
)
)

# =====================================================
# SWC
# =====================================================

swc = componentPkg.createApplicationSoftwareComponent(
"BrakeController"
)

# =====================================================
# Ports
# =====================================================

swc.createProvidePort(
"BrakePosition_PPort",
"BrakePosition_I"
)

swc.createRequirePort(
"BrakePosition_RPort",
"BrakePosition_I"
)

# =====================================================
# Internal Behavior
# =====================================================

behavior = swc.behavior

runnable = behavior.createRunnable(
"BrakeRunnable"
)

# =====================================================
# Timing Event
# =====================================================

behavior.createTimerEvent(
"BrakeRunnable",
period=10
)

# =====================================================
# Save ARXML
# =====================================================

ws.saveXML("BrakeController.arxml")

print("===================================")
print("SWC generado correctamente")
print("Archivo: BrakeController.arxml")
print("SWC: BrakeController")
print("Runnable: BrakeRunnable")
print("Interface: BrakePosition_I")
print("===================================")