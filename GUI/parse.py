'''
ex: A
ex: (A) & (B)
ex: ((A) & (B)) | (C)
ex: (~A) or ~A
'''
string = "((A) & (B)) | (C)"
print("String:", string)
raw = list(string) # first breaks up the string into

invalid = False
operation = {"&", "|", ">", "="} # symbols that need two symbols next to them
# symbols that only need one: ~
# symbols that need to be completed: ( )

def next(raw, current):
	if current < len(raw) - 1:
		return(True, raw[current + 1])
	return(False, raw[current])

def matching(string):# function that returns a dictionary of matching parentheses
	par = {}
	stackParen = [] # a stack of the indecies of parentheses
	for i in range(len(string)):
		if string[i] == "(":
			# adds a
			stackParen.append(i)
			par[i] = -1
		elif string[i] == ")":
			# do another thing
			if not stackParen:
				return (False, {})
			par[stackParen[len(stackParen) - 1]] = i
			del stackParen[len(stackParen) - 1]
	for i in par:
		if par[i] == -1:
			return (False, {})
	return (True, par)

(matches, loc) = matching(string)
print(loc)
'''
paren = {"(": 0, ")":0} # keeps track of the number of parenthisis
prev = "" #keeps track of the previous item

index = 0
first = True
# assume that the inputs will have spaces next to them
for symbol in raw:
	if symbol == " ":
		if first:
			invalid = True
			break
		continue

	if symbol == "(": # good
		if prev == "sy" or prev == ")":
			invalid = True
			break
		paren[symbol] += 1
		prev = symbol

	elif symbol == ")": # good
		if prev == "(" or prev == "op" or prev == "~" or first:
			invalid = True
			break
		paren[symbol] += 1
		prev = symbol

	elif symbol in operation: # good
		if prev == ")":
			# Only good input is if there is a ) before an operation
			prev = "op"
		else:
			invalid = True
			break
((c) -> (((A) & (B)) & (D))) -> (D)
	elif symbol == "~": # good
		if prev == "op" or prev == ")":
			invalid = True
			break
		prev = symbol
		# make sure the next symbol

	else:
		if prev == ")" or prev == "op":
			invalid = True
			break
		if first: # edge case for the first item
			if next(raw, 0)[0] == False: # checks if it is the only character
				invalid = True
				break
		prev = "sy"
		# symbol must be a letter then
		# will deal with additional symbols later
	index += 1
	first = False

if invalid:
	print("Invalid string")
elif paren[")"] is not paren["("]:
    print("Invalid string: Mismatching number of parenthsis")
else:
	print("Valid string")
'''