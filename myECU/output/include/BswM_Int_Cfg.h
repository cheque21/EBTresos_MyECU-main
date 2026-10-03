#ifndef BSWM_INT_CFG_H
#define BSWM_INT_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.15.5
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/*==================[inclusions]============================================*/

/* !LINKSTO BswM0025,1, BswM0001,1, BswM0008,1 */
/* The BswM includes the the header files of all other BSW modules
 * which API functions it uses when the BSW module is enabled.
 */

#include <SchM_BswM.h>

#include <BswM_Types.h>

/* !LINKSTO BswM00954_Conf,1 */
/* No user header files to be included found */

/*==================[macros]=================================================*/

#if (defined BSWM_IS_MULTICORE_ECU)
#error BSWM_IS_MULTICORE_ECU already defined
#endif

#define BSWM_IS_MULTICORE_ECU FALSE

#if (defined BSWM_GET_INSTANCE_BSW_DISTRIBUTION)
#error BSWM_GET_INSTANCE_BSW_DISTRIBUTION already defined
#endif

#define BSWM_GET_INSTANCE_BSW_DISTRIBUTION FALSE

#if (defined BSWM_IS_VARIANT_PRECOMPILE)
#error BSWM_IS_VARIANT_PRECOMPILE already defined
#endif

#define BSWM_IS_VARIANT_PRECOMPILE TRUE

#if (defined BSWM_GET_APPLICATION_ID)
#error BSWM_GET_APPLICATION_ID already defined
#endif

#define BSWM_GET_APPLICATION_ID() 0U

#if (defined BSWM_DEFERRED_ACTIONS_QUEUE_SIZE)
#error BSWM_DEFERRED_ACTIONS_QUEUE_SIZE is already defined
#endif

#define BSWM_DEFERRED_ACTIONS_QUEUE_SIZE 0U

#if (defined BSWM_GET_LOG_EXPR_INIT_STATUS)
#error BSWM_GET_LOG_EXPR_INIT_STATUS is already defined
#endif

#if (defined BSWM_SET_LOG_EXPR_INIT_STATUS)
#error BSWM_SET_LOG_EXPR_INIT_STATUS is already defined
#endif

#define BSWM_GET_LOG_EXPR_INIT_STATUS(exprIndex) 0U
#define BSWM_SET_LOG_EXPR_INIT_STATUS(exprIndex, value)

#if (defined BSWM_GET_EXPR_STATE)
#error BSWM_GET_EXPR_STATE is already defined
#endif

#define BSWM_GET_EXPR_STATE(exprIndex) ((inst)->LinkTimeContext->logicalExprGetStateFuncPtr((exprIndex)))

#if (defined BSWM_GET_EXPR_RESULT)
#error BSWM_GET_EXPR_RESULT is already defined
#endif

#define BSWM_GET_EXPR_RESULT(exprIndex) ((inst)->LinkTimeContext->logicalExprGetResultFuncPtr((exprIndex)))

#if (defined BSWM_EXECUTE_ACTION)
#error BSWM_EXECUTE_ACTION is already defined
#endif

#define BSWM_EXECUTE_ACTION(ActionIndex) ((inst)->LinkTimeContext->executeActionFuncPtr((ActionIndex)))

/* All the values of the BswMModeRequestSourceType */

#if (defined BSWM_TIMER_CONTROL_ACTIONS_USED)
#error BSWM_TIMER_CONTROL_ACTIONS_USED is already defined
#endif
#define BSWM_TIMER_CONTROL_ACTIONS_USED STD_OFF

#if (defined BSWM_TIMER_TABLE_SIZE)
#error BSWM_TIMER_TABLE_SIZE is already defined
#endif
#define BSWM_TIMER_TABLE_SIZE 0U

/*==================[type definitions]=======================================*/

typedef struct
{
  void* port;
  uint32 mode;
  uint8 type;
} BswMRequestType;

typedef uint8 BswMModeRequestSourceType;

typedef P2FUNC(void, TYPEDEF, BswMExclusiveAreaFuncPtrType)(void);

/** \brief Function pointer type for a BswM action function. */
typedef P2FUNC(Std_ReturnType, TYPEDEF, BswMActionFuncPtrType)(void);

/** \brief may be assigned the values BSWM_TRUE, BSWM_FALSE or BSWM_UNDEFINED */
typedef uint8 BswMResultType;

/** \brief Function pointer type for a BswM logical expression function. */
typedef P2FUNC(BswMResultType, TYPEDEF, BswMExprResultFuncPtrType)(void);

/** \brief Function point type for access to the initialized state of a logical
 ** expression. */
typedef P2FUNC(boolean, TYPEDEF, BswMExprStateFuncPtrType)(void);

/** \brief Data structure type for a BswM logical expression */
typedef struct
{
  /* A pointer to a function which will return TRUE when the corresponding mode
   * request port and nested logical expressions are all initialized.
   * Otherwise, the function will return false. */
  BswMExprStateFuncPtrType GetState;
  /* A pointer to the function which will evaluate the expression. */
  BswMExprResultFuncPtrType GetResult;
} BswMLogicalExprType;

 /**
 * BswM_IndexType
 */
typedef uint16 BswM_IndexType;
/**
 * BswM_RunTimeContextType
 */
typedef struct 
{
  VAR( BswMResultType , BSWM_VAR_NOINIT ) RuleResultTable[1]; /* RuleResultTable */
  uint8 IsInitialized; /* IsInitialized */
} BswM_RunTimeContextType;

/**
 * BswM_LinkTimeContextType
 */
typedef struct 
{
  BswMResultType ( *logicalExprGetStateFuncPtr )( uint16 ); /* logicalExprGetStateFuncPtr */
  BswMResultType ( *logicalExprGetResultFuncPtr )( uint16 ); /* logicalExprGetResultFuncPtr */
  Std_ReturnType ( *executeActionFuncPtr )( uint16 ); /* executeActionFuncPtr */
  Std_ReturnType ( *handleStaticRequestFuncPtr )( uint32, uint16, uint8, uint8 ); /* handleStaticRequestFuncPtr */
  uint16 numBswMExpressions; /* numBswMExpressions */
} BswM_LinkTimeContextType;

/**
 * BswM_PartitionContextType
 */
typedef struct 
{
  BswMExclusiveAreaFuncPtrType SchMEnter; /* SchMEnter */
  BswMExclusiveAreaFuncPtrType SchMExit; /* SchMExit */
  BswM_LinkTimeContextType *LinkTimeContext; /* LinkTimeContext */
  BswM_RunTimeContextType RunTimeContext; /* RunTimeContext */
  CONST( uint8, AUTOMATIC ) ID; /* ID */
} BswM_PartitionContextType;

/**
 * UInt8SymbolicValue
 */
typedef uint8 UInt8SymbolicValue;

/**
 * BswMBasicPortType
 */
typedef struct 
{
  uint16 id; /* id */
  uint8 isImmediate; /* isImmediate */
  uint8 isDefined; /* isDefined */
} BswMBasicPortType;

/**
 * BswMModeRequestPortType
 */
typedef struct 
{
  BswMBasicPortType base; /* base */
  UInt8SymbolicValue channel; /* channel */
  uint8 mode; /* mode */
} BswMModeRequestPortType;

/**
 * BswMGenericRequestPortType
 */
typedef struct 
{
  BswMBasicPortType base; /* base */
  uint16 channel; /* channel */
  uint16 mode; /* mode */
} BswMGenericRequestPortType;

/**
 * BswMJ1939NmStateChangeNotificationPortType
 */
typedef struct 
{
  BswMBasicPortType base; /* base */
  uint16 channel; /* channel */
  uint8 mode; /* mode */
} BswMJ1939NmStateChangeNotificationPortType;

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function declarations]==========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

/** \brief Performs the mode arbitration of a mode request port
 **
 ** \param inst The BswM instance the port belongs to
 ** \param port Pointer to the mode request port object
 ** \param mode The new mode of the port
 ** \param type The type of the mode request port
 **/
extern FUNC(void, BSWM_CODE) BswM_ExecuteModeArbitration
(
P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_VAR) inst,
P2VAR(void, AUTOMATIC, BSWM_VAR) port,
uint32 mode,
uint8 type
);

extern FUNC_P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_CODE) BswM_GetInstance(void);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[internal function declarations]==========================*/
/** @} doxygen end group definition */
#endif /* ifndef BSWM_INT_CFG_H */
/*==================[end of file]============================================*/

