/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \version 5.0.30
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */
#ifndef BASE_MODULES_H
#define BASE_MODULES_H

/*==================[macros]=================================================*/

#ifndef BASE_BASE_ENABLED
/** \brief Enable status of the module Base (/Base/Base) (VariantPreCompile) */
#define BASE_BASE_ENABLED STD_ON
#endif

#ifndef BASE_BASE_HEADER
/** \brief Name of the Base (/Base/Base) module's main header file */
#define BASE_BASE_HEADER <Base.h>
#endif

#ifndef BASE_BSWM_ENABLED
/** \brief Enable status of the module BswM (/BswM/BswM) (VariantPreCompile) */
#define BASE_BSWM_ENABLED STD_ON
#endif

#ifndef BASE_BSWM_HEADER
/** \brief Name of the BswM (/BswM/BswM) module's main header file */
#define BASE_BSWM_HEADER <BswM.h>
#endif

#ifndef BASE_COMPILER_ENABLED
/** \brief Enable status of the module Compiler (/Compiler/Compiler) (VariantPreCompile) */
#define BASE_COMPILER_ENABLED STD_ON
#endif

#ifndef BASE_COMPILER_HEADER
/** \brief Name of the Compiler (/Compiler/Compiler) module's main header file */
#define BASE_COMPILER_HEADER <Compiler.h>
#endif

#ifndef BASE_DET_ENABLED
/** \brief Enable status of the module Det (/Det/Det) (VariantPreCompile) */
#define BASE_DET_ENABLED STD_ON
#endif

#ifndef BASE_DET_HEADER
/** \brief Name of the Det (/Det/Det) module's main header file */
#define BASE_DET_HEADER <Det.h>
#endif

#ifndef BASE_MCALEXT_ENABLED
/** \brief Enable status of the module McalExt (/McalExt/McalExt) (VariantPreCompile) */
#define BASE_MCALEXT_ENABLED STD_ON
#endif

#ifndef BASE_MCALEXT_HEADER
/** \brief Name of the McalExt (/McalExt/McalExt) module's main header file */
#define BASE_MCALEXT_HEADER <McalExt.h>
#endif

#ifndef BASE_MCALLIB_ENABLED
/** \brief Enable status of the module McalLib (/McalLib/McalLib) (VariantPreCompile) */
#define BASE_MCALLIB_ENABLED STD_OFF
#endif

#ifndef BASE_MCALLIB_HEADER
/** \brief Name of the McalLib (/McalLib/McalLib) module's main header file */
#define BASE_MCALLIB_HEADER <McalLib.h>
#endif

#ifndef BASE_RESOURCEM_ENABLED
/** \brief Enable status of the module ResourceM (/ResourceM/ResourceM) (VariantPreCompile) */
#define BASE_RESOURCEM_ENABLED STD_ON
#endif

#ifndef BASE_RESOURCEM_HEADER
/** \brief Name of the ResourceM (/ResourceM/ResourceM) module's main header file */
#define BASE_RESOURCEM_HEADER <ResourceM.h>
#endif

#endif /* ifndef BASE_MODULES_H */
/*==================[end of file]============================================*/
