-- k-Nearest Neighbour algorithm
-- by Darksun2010

-- dataSet format:{{X,Y,Z,..},type}
function classify(inX,dataSet,k)
	local distSet={};
	for _,v in pairs(dataSet) do
		local pos,set=v[1],v[2];
		local distSum=0;
		for i=1,#pos do
			distSum=distSum+(pos[i]-inX[i])^2;
		end
		table.insert(distSet,{math.sqrt(distSum),set});
	end
	table.sort(distSet,function(a,b) return a[1]<b[1]; end);
	local timeSet={};
	for i=1,k do
		local T=distSet[i][2];
		if (timeSet[T]) then
			timeSet[T]=timeSet[T]+1;
		else 
			timeSet[T]=1;
		end
	end
	local max=0,maxn;
	for k,v in pairs(timeSet) do
		if v>max then
			max,maxn=v,k
		end
	end
	return maxn;
end
