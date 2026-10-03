
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

/* !LINKSTO BswM0024,1 */
/* The BswM_Lcfg.c contains all link-time configuration parameters. */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_c,1 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 17.8 (advisory)
 * A function parameter should not be modified.
 *
 * Reason:
 * For BswMJ1939DcmBroadcastStatus ports the mode parameter has no significance
 * and it intentionally set to 0 when calling the HandleStaticRequest function.
 * It is then directly modified in order to call the BswM_HandleRequest function
 * with the correct mode (depending on the current channel) in order to avoid
 * creating a new stack variable.
 */

/*==================[inclusions]============================================*/

#include <BswM_Trace.h>       /* Dbg macros */
#include <BswM.h>
#include <BswM_Int_Cfg.h>
#include <BswM_Int.h>
#include <TSMem.h>            /* Used for TS_MemSet */
#include <SchM_BswM.h>        /* SchM API for BswM         */

#include <BswM_Lcfg.h>

/*==================[macros]================================================*/

#define BSWM_INVALID_INITIAL_VALUE_INDEX 0xFFU

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceCode,1 */
#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceData,1 */
#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

/* Dynamically Generated Mode Request Ports */

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>
/**
 * BswM_LinkTimeContext
 */
STATIC BswM_LinkTimeContextType BswM_LinkTimeContext = 
{
  NULL_PTR, /* logicalExprGetStateFuncPtr */
  NULL_PTR, /* logicalExprGetResultFuncPtr */
  NULL_PTR, /* executeActionFuncPtr */
  NULL_PTR, /* handleStaticRequestFuncPtr */
  UINT16_C( 0 )  /* numBswMExpressions */
};

/**
 * BswM_Context
 */
BswM_PartitionContextType BswM_Context = 
{
  &SchM_Enter_BswM_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMEnter */
  &SchM_Exit_BswM_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMExit */
  &BswM_LinkTimeContext, /* LinkTimeContext */
  { /* RunTimeContext */
    { /* RuleResultTable */
      UINT8_C( 0 )  /* [0] */
    },
    UINT8_C( 0 )  /* IsInitialized */
  },
  UINT8_C( 0 )  /* ID */
};

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

/*==================[external function definitions]=========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

FUNC(void, BSWM_CODE) BswM_LT_Init(void)
{
  DBG_BSWM_LT_INIT_ENTRY();

  /* !LINKSTO SWS_BswM_00251,1 */

  DBG_BSWM_LT_INIT_EXIT();
}

/*==================[internal function definitions]=========================*/

/* INDENT:OFF */

/* INDENT:ON */

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
