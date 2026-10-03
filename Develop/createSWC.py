import autosar

ws = autosar.workspace("4.2.2")

package = ws.createPackage('ComponentTypes', role='ComponentType')

swc = package.createApplicationSoftwareComponent(
'BrakeController'
)

ws.saveXML('BrakeController.arxml')