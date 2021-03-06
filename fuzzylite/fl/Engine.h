/*
 Author: Juan Rada-Vilela, Ph.D.
 Copyright © 2010-2015 FuzzyLite Limited.
 All rights reserved.

 This file is part of fuzzylite®.

 fuzzylite® is free software: you can redistribute it and/or modify it under
 the terms of the FuzzyLite License included with the software.

 You should have received a copy of the FuzzyLite License along with 
 fuzzylite®. If not, see <http://www.fuzzylite.com/license/>.

 fuzzylite® is a registered trademark of FuzzyLite Limited.

 */

#ifndef FL_ENGINE_H
#define FL_ENGINE_H

#include "fl/fuzzylite.h"

#include "fl/defuzzifier/IntegralDefuzzifier.h"

#include <string>
#include <vector>

namespace fl {

    class InputVariable;
    class OutputVariable;
    class Variable;
    class RuleBlock;
    class Hedge;
    class TNorm;
    class SNorm;
    class Defuzzifier;

    class FL_API Engine {
    private:
        std::string _name;
        std::vector<InputVariable*> _inputVariables;
        std::vector<OutputVariable*> _outputVariables;
        std::vector<RuleBlock*> _ruleblocks;

        void copyFrom(const Engine& source);

    protected:
        void updateReferences() const;

    public:
        explicit Engine(const std::string& name = "");
        Engine(const Engine& other);
        Engine& operator=(const Engine& other);
        virtual ~Engine();
        FL_DEFAULT_MOVE(Engine)

        virtual void configure(const std::string& conjunctionT,
                const std::string& disjunctionS,
                const std::string& implicationT,
                const std::string& accumulationS,
                const std::string& defuzzifier);

        virtual void configure(TNorm* conjunction, SNorm* disjunction,
                TNorm* implication, SNorm* accumulation,
                Defuzzifier* defuzzifier);

        virtual bool isReady(std::string* status = fl::null) const;

        virtual void process();

        virtual void restart();

        virtual void setName(const std::string& name);
        virtual std::string getName() const;

        virtual void setInputValue(const std::string& name, scalar value);
        virtual scalar getOutputValue(const std::string& name);

        virtual std::string toString() const;

        enum Type {
            Mamdani, Larsen, TakagiSugeno,
            Tsukamoto, InverseTsukamoto, Hybrid, Unknown
        };
        virtual Type type(std::string* name = fl::null, std::string* reason = fl::null) const;

        virtual Engine* clone() const;

        virtual std::vector<Variable*> variables() const;

        /**
         * Operations for iterable datatype _inputVariables
         */
        virtual void addInputVariable(InputVariable* inputVariable);
        virtual InputVariable* setInputVariable(InputVariable* inputVariable, std::size_t index);
        virtual void insertInputVariable(InputVariable* inputVariable, std::size_t index);
        virtual InputVariable* getInputVariable(std::size_t index) const;
        virtual InputVariable* getInputVariable(const std::string& name) const;
        virtual InputVariable* removeInputVariable(std::size_t index);
        virtual InputVariable* removeInputVariable(const std::string& name);
        virtual bool hasInputVariable(const std::string& name) const;
        virtual std::size_t numberOfInputVariables() const;
        virtual const std::vector<InputVariable*>& inputVariables() const;
        virtual void setInputVariables(const std::vector<InputVariable*>& inputVariables);
        virtual std::vector<InputVariable*>& inputVariables();

        /**
         * Operations for iterable datatype _outputVariables
         */
        virtual void addOutputVariable(OutputVariable* outputVariable);
        virtual OutputVariable* setOutputVariable(OutputVariable* outputVariable, std::size_t index);
        virtual void insertOutputVariable(OutputVariable* outputVariable, std::size_t index);
        virtual OutputVariable* getOutputVariable(std::size_t index) const;
        virtual OutputVariable* getOutputVariable(const std::string& name) const;
        virtual bool hasOutputVariable(const std::string& name) const;
        virtual OutputVariable* removeOutputVariable(std::size_t index);
        virtual OutputVariable* removeOutputVariable(const std::string& name);
        virtual std::size_t numberOfOutputVariables() const;
        virtual const std::vector<OutputVariable*>& outputVariables() const;
        virtual void setOutputVariables(const std::vector<OutputVariable*>& outputVariables);
        virtual std::vector<OutputVariable*>& outputVariables();

        /**
         * Operations for iterable datatype _ruleblocks
         */
        virtual void addRuleBlock(RuleBlock* ruleblock);
        virtual RuleBlock* setRuleBlock(RuleBlock* ruleBlock, std::size_t index);
        virtual void insertRuleBlock(RuleBlock* ruleblock, std::size_t index);
        virtual RuleBlock* getRuleBlock(std::size_t index) const;
        virtual RuleBlock* getRuleBlock(const std::string& name) const;
        virtual bool hasRuleBlock(const std::string& name) const;
        virtual RuleBlock* removeRuleBlock(std::size_t index);
        virtual RuleBlock* removeRuleBlock(const std::string& name);
        virtual std::size_t numberOfRuleBlocks() const;
        virtual const std::vector<RuleBlock*>& ruleBlocks() const;
        virtual void setRuleBlocks(const std::vector<RuleBlock*>& ruleBlocks);
        virtual std::vector<RuleBlock*>& ruleBlocks();

    };

}
#endif /* FL_ENGINE_H */
