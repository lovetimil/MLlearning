-- Discriminating digit
-- by Darksun2010

local kNN=require("kNN");
assert(kNN);
local testPath=".\\digits\\testDigits\\";
local trainingPath=".\\digits\\trainingDigits\\";
local k=3;

function image2Data(fileName)
	local dFile,err=io.open(fileName);
	if dFile==nil then
		return nil;
	end
	local data=dFile:read("*all");
	io.close(dFile);
	return {string.byte(data,1,#data)};
end

function getInitData()
	local result={};
	for i=0,9 do
		local j=0;
		repeat
			local fileName=table.concat({trainingPath,i,"_",j,".txt"});
			local thisData=image2Data(fileName);
			if thisData==nil then
				break;
			end
			table.insert(result,{thisData,i});
			j=j+1;
		until false;
	end
	return result;
end

function testkNN()
	local trained=getInitData();
	local total,WA=0,0;
	for i=0,9 do 
		local j=0;
		repeat
			local fileName=table.concat({testPath,i,"_",j,".txt"});
			local thisData=image2Data(fileName);
			if thisData==nil then
				break;
			end
			local result=classify(thisData,trained,k);
			if not (result==i) then
				WA=WA+1;
			end
			print("answer of kNN: ",result," , correct answer: ",i);
			total=total+1;
			j=j+1;
		until false;
	end
	return total,WA/total;
end
