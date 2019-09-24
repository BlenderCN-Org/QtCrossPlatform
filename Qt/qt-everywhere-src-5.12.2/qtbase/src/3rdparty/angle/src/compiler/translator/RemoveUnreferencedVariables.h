//
// Copyright (c) 2017 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// RemoveUnreferencedVariables.h:
//  Drop variables that are declared but never referenced in the AST. This avoids adding unnecessary
//  initialization code for them. Also removes unreferenced struct types.
//

#ifndef COMPILER_TRANSLATOR_REMOVEUNREFERENCEDVARIABLES_H_
#define COMPILER_TRANSLATOR_REMOVEUNREFERENCEDVARIABLES_H_

namespace sh
{

class TIntermBlock;
class TSymbolTable;

void RemoveUnreferencedVariables(TIntermBlock *root, TSymbolTable *symbolTable);

}  // namespace sh

#endif  // COMPILER_TRANSLATOR_REMOVEUNREFERENCEDVARIABLES_H_
